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
	const int hash = HashFunction(key);
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

// TODO: fix Remove to work with the toCheck iteration
void HashMap::Remove(const std::string& key)
{
	const int hash = HashFunction(key);
	LinkedListEntry* toCheck = entries[hash];
	while (toCheck != nullptr)
	{
		if (toCheck->key == key)
		{
			// BUG! Cannot just null entry at hash. Must get to the element that toCheck is! In case it got collided and moved with ->next
			entries[hash] = nullptr;
			toCheck = nullptr; // This also just sets this pointer to null. I must get the entries[target] to null
			return;
		}

		toCheck = toCheck->next;
	}
}

int HashMap::HashFunction(const std::string& key)
{
	int hashDigest = 0;
	for (const char c : key)
	{
		hashDigest += static_cast<int>(c);
	}
	return hashDigest % size;
}
