#ifndef MAP_H
#define MAP_H
#include "MapEntry.hpp"
#include <string>
#include <vector>

class Map {
public:
	void Insert(std::string key, std::string value);
	std::string Lookup(std::string key);
	void Remove(std::string key);
private:
	std::vector<MapEntry> entries;
};
#endif