#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
#include "Search.h"
#include "ItemManager.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <limits>

// Performance = Measurements
// An ugly header to do some measurements. Just to archive it

class Measurements
{
public:
	// Format and print a vector of std::chrono::duration measurement results
	void PrintResults(std::vector<std::chrono::duration<double>> results)
	{
		int i = 0; // index
		long long lowestNs = std::numeric_limits<long long>::max();
		long long highestNs = std::numeric_limits<long long>::min();

		std::chrono::duration<double> totalTime{};

		for (auto result : results)
		{
			// Do the comparison in nanoseconds for accuracy's sake
			auto nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(result);
			 std::cout << "result_" << i << " = " << nanoSec.count() << " ns. | ";

			if (nanoSec.count() < lowestNs)
			{
				lowestNs = nanoSec.count();
			}
			if (nanoSec.count() > highestNs)
			{
				highestNs = nanoSec.count();
			}
			++i;
			totalTime += result;
		}
		std::cout << '\n';

		auto average = totalTime / i;
		auto median = results[i / 2];
		long long averageNs = std::chrono::duration_cast<std::chrono::nanoseconds>(average).count();
		long long medianNs = std::chrono::duration_cast<std::chrono::nanoseconds>(median).count();
		std::cout << "Highest = " << FormatNanoseconds(highestNs) << '\n';
		std::cout << "Lowest  = " << FormatNanoseconds(lowestNs) << '\n';
		std::cout << "Average = " << FormatNanoseconds(averageNs) << '\n';
		std::cout << "Median  = " << FormatNanoseconds(medianNs) << '\n';
		std::cout << '\n';
	}

	// An ugly function just to archive the code
	void MeasureBinarySearch()
	{
		constexpr int toFind = 40;
		constexpr int MAX_ITEMS = 255000;
		auto items = new Item[MAX_ITEMS];

		ItemManager itemManager;

		// Populated in order because sorting is slow
		itemManager.PopulateItemsInOrder(items, MAX_ITEMS);

		// Temporary array of just the gold entires for the search
		int goldArray[MAX_ITEMS];
		for (int i = 0; i < MAX_ITEMS; ++i)
		{
			goldArray[i] = items[i].goldValue;
		}

		Search search;

		std::vector<std::chrono::duration<double>> results;

		for (int i = 0; i < 10; ++i)
		{
			auto start{std::chrono::steady_clock::now()}; // Physical time, not CPU time

			auto find = search.BinarySearch<int*, std::uint32_t>(goldArray, &goldArray[0], &goldArray[255], toFind);
			// auto find = search.BinarySearchLowBound(&goldArray[0], &goldArray[255], toFind);
			// auto find = std::binary_search(&goldArray[0], &goldArray[255], toFind); // Returns a bool
			auto end{std::chrono::steady_clock::now()};

			results.push_back(end - start);
		}

		PrintResults(results);

		delete[] items;
	}

private:
	std::string FormatNanoseconds(long long ns)
	{
		const std::string milliseconds = std::to_string(ns / 1000000LL);
		const std::string microseconds = std::to_string(ns / 1000LL);

		std::string s = milliseconds + "ms. " + microseconds + "us. " + std::to_string(ns) + "ns.";
		return s;
	}
};


#endif
