#ifndef LINKEDLISTENTRY_H
#define LINKEDLISTENTRY_H
#include <string>
struct LinkedListEntry {
	std::string key{};
	std::string value{};

	LinkedListEntry(const std::string& key = "", const std::string& value = "") {
		this->key = key;
		this->value = value;
	}

	LinkedListEntry* next = nullptr;

	LinkedListEntry* Last() {
		if (next == nullptr) {
			return this;
		}
		LinkedListEntry* last = next;
		while (last->next)
			last = last->next;
		return last;
	}
};
#endif