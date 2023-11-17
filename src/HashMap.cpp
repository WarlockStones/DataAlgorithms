#include "HashMap.hpp"

void HashMap::Initialize(int size)
{
	this->size = size;

	entries = new LinkedListEntry*[size]{}; // braced{} to initialized every pointer as nullptr
}

void HashMap::Insert(std::string key, std::string value)
{
	int hash = HashFunction(key);
	if (entries[hash] == nullptr)
	{
		entries[hash] = new LinkedListEntry(key, value); // Dynamic allocation. Won't this be slower?
	}
	else
	{
		entries[hash]->Last()->next = new LinkedListEntry(key, value);
	}
}

std::string HashMap::Lookup(std::string key)
{
	int hash = HashFunction(key);
	if (entries[hash] == nullptr)
		return ""; // Instead of return nullptr
	LinkedListEntry* toCheck = entries[hash];
	while (toCheck != nullptr)
	{
		if (toCheck->key == key)
			return toCheck->value;
		toCheck = toCheck->next;
	}

	return "";
}

int HashMap::HashFunction(const std::string& key)
{
	int hashDigest = 0;
	for (char c : key)
	{
		hashDigest += static_cast<int>(c);
	}
	return hashDigest % size;
}
