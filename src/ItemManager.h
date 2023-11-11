#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include "Item.h"

class ItemManager
{
public:
	// Populate item values according to index. Because sorting is slow
	void PopulateItemsInOrder(Item* array, const int MAX_SIZE);

	// Generate random items for an Item array
	void GenerateItems(Item* array, const int MAX_SIZE);

	// Sort items by gold using a selection short algorithm
	void SortItemsByGold(Item* array, const int MAX_SIZE);

	// Print a single item and its contents
	void PrintItem(const Item& item);
};
#endif
