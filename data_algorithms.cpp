#include <iostream>
#include "ItemManager.h"
#include "Search.h"
#include <algorithm>
#include <chrono>

// TODO: Test measurements. Increase array size until we see difference

int main()
{
    const int MAX_ITEMS = 255;
    Item items[MAX_ITEMS];

    ItemManager itemManager;
    itemManager.GenerateItems(items, MAX_ITEMS);

    // Sort items before Binary Search!!
    itemManager.SortItemsByGold(items, MAX_ITEMS);

    for (auto item : items) {
        itemManager.PrintItem(item);
    }

    const int toFind = 40;

    // To use std::binary_search I would have to create an array of all gold items!
    int goldArray[MAX_ITEMS];
    for (int i = 0; i<MAX_ITEMS; ++i) {
        goldArray[i] = items[i].goldValue;
    }



    Search search;

    auto start{ std::chrono::steady_clock::now() }; // Physical time, not CPU time
    auto find = search.BinarySearch<int*, std::uint32_t>(goldArray, &goldArray[10], &goldArray[240], toFind);
    auto end{ std::chrono::steady_clock::now()};
    // End is past-the-last element. It will be garbage data
    if (find != &goldArray[MAX_ITEMS]) // If it is not .end()
    {
        std::cout << "good!\n";
        std::cout << "find = " << *find << '\n';
	    
    }
    else
        std::cout << "Bad! Could not find value\n";

    std::chrono::duration<double> elapsedSeconds{ end - start };
    std::cout << "My binary search time: " << elapsedSeconds.count() << "s\n";
}
