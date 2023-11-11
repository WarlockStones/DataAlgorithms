#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
#include "Search.h"
#include "ItemManager.h"
#include <vector>
#include <chrono>
#include <limits>

// Performance = Measurements
// An ugly header to do some measurements. Just to archive it

class Measurements{
public:
    void PrintResults(std::vector<std::chrono::duration<double>> results){
        int i = 0; // index
        // Conversion from chrono to double bad?
        double lowestNs = std::numeric_limits<double>::max();
        double highestNs = std::numeric_limits<double>::min();

        std::chrono::duration<double> totalTime{};
        
	for (auto result : results){
            std::cout<<"Result for index_"<<i<<'\n';

	    auto microSec = std::chrono::duration_cast<std::chrono::microseconds>(result);
	    std::cout << microSec.count() << "ms\n";
	    auto nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(result);
	    std::cout << nanoSec.count() << "ns\n";
            std::cout<<'\n';
           
            if (nanoSec.count() < lowestNs){
                lowestNs = nanoSec.count();
	    }
            if (nanoSec.count() > highestNs){
                highestNs = nanoSec.count(); 
	    }
            ++i;
            totalTime += result;
	}
        // TODO: Get Highest. Lowest. Average. Median
        auto average = totalTime/i;
        auto averageNs = std::chrono::duration_cast<std::chrono::nanoseconds>(average);
        auto median = results[i/2];
        auto medianNs = std::chrono::duration_cast<std::chrono::nanoseconds>(median);
        std::cout<<"Highest result = "<<highestNs<<"ns\n";
        std::cout<<"Lowest  result = "<<lowestNs<<"ns\n";
        std::cout<<"Average result = "<<averageNs.count()<<"ns\n";
        std::cout<<"Median  result = "<<medianNs.count()<<"ns\n";
    }

    // An ugly function just to archive the code
    void MeasureBinarySearch(){
	const int toFind = 40;
	const int MAX_ITEMS = 255000;
	Item* items = new Item[MAX_ITEMS];

	ItemManager itemManager;

        // Populated in order because sorting is slow
	itemManager.PopulateItemsInOrder(items, MAX_ITEMS);
        
        // Temporary array of just the gold entires for the search
	int goldArray[MAX_ITEMS];
	for (int i = 0; i<MAX_ITEMS; ++i) {
	    goldArray[i] = items[i].goldValue;
	}

	Search search;

	std::vector<std::chrono::duration<double>> results;

        for (int i = 0; i < 10; ++i){
	    auto start{ std::chrono::steady_clock::now() }; // Physical time, not CPU time
	    auto find = 
                search.BinarySearch<int*, std::uint32_t>(goldArray,
		  					 &goldArray[10],
							 &goldArray[240],
                                                         toFind);
	    auto end{ std::chrono::steady_clock::now()};

            results.push_back(end-start);
	}

        PrintResults(results);

	delete[] items;
    }

};


#endif
