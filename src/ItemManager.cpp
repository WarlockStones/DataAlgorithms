#include "ItemManager.h"
#include <random>
#include <iostream>

void ItemManager::PopulateItemsInOrder(Item* array, const int MAX_SIZE)
{
	for (int i = 0; i < MAX_SIZE; ++i) // C-loop to use index
	{
		array[i].goldValue = i;

		std::string name = "MyAwesomeItem_";
		name += std::to_string(i);
		array[i].name = name;

		array[i].weight = i;
	}
}

// Randomly generate items
void ItemManager::GenerateItems(Item* array, const int MAX_SIZE)
{
	// C-random
	srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 0; i < MAX_SIZE; ++i) // C-loop to use index
	{
		array[i].goldValue = rand() % 100;

		std::string name = "MyAwesomeItem_";
		name += std::to_string(rand() % 100);
		array[i].name = name;


		/*
		std::mt19937 gen{std::random_device{}()};
		std::uniform_int_distribution<int> distribution{'a', 'z'};
		int stringLength = 6;
		std::string randStr(stringLength, '\0');
		for (auto& dist : randStr)
		{
			dist = distribution(gen);
		}

		std::string name = "MyAwesomeItem_";
		name += randStr;
		array[i].name = name;
		*/


		array[i].weight = rand() % 100;
	}
}

void ItemManager::SortItemsByGold(Item* array, const int MAX_SIZE)
{
	for (int x = 0; x < MAX_SIZE; ++x)
	{
		int lowestGoldValueIndex = x;

		for (int y = x + 1; y < MAX_SIZE; ++y)
		{
			if (array[y].goldValue < array[lowestGoldValueIndex].goldValue)
			{
				lowestGoldValueIndex = y;
			}
		}
		// The actual swapping.
		if (array[x].goldValue != array[lowestGoldValueIndex].goldValue)
		{
			// Swap the items. items[x] to be items[lowestGoldValueIndex]
			Item oldItemX = array[x];
			array[x] = array[lowestGoldValueIndex];
			array[lowestGoldValueIndex] = oldItemX;
		}
	}
}

void ItemManager::PrintItem(const Item& item)
{
	std::cout << item.name << ". " << item.goldValue << "gp. " << item.weight << "w.\n";
}
