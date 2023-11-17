#include "Map.hpp"
#include "MapEntry.hpp"

void Map::Insert(std::string key, std::string value) {
	// Add it new entry to entries
	MapEntry e;
	e.key = key;
	e.value = value;
	entries.push_back(e);
}

std::string Map::Lookup(std::string key)
{
	for (auto entry : entries)
	{
		if (entry.key == key)
			return entry.value;
	}
	return ""; 
}

void Map::Remove(std::string key)
{
	// search for loop and remove
	std::vector<MapEntry>::iterator iter = entries.begin();
	while (iter != entries.end())
	{
		if (iter->key == key)
		{
			iter = entries.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}
