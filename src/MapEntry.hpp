#ifndef MAPENTRY_H
#define MAPENTRY_H
#include <string>
struct MapEntry {
	std::string key{};
	std::string value{};

	friend bool operator== (const MapEntry& left, const MapEntry& right) {
		if (left.key == right.key)
				return true;
		return false;
	}
};
#endif