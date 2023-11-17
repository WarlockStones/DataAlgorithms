#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include "LinkedListEntry.hpp"
class HashMap {
public:
	void Initialize(int size);
	void Insert(std::string key, std::string value);
	std::string Lookup(std::string key);
	void Remove(const std::string& key);
private:
	int HashFunction(const std::string& key);
	int size{};
	LinkedListEntry** entries; // pointer pointer, to be allocated to array of pointers
};

#endif