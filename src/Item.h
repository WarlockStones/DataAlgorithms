#ifndef ITEM_H
#define ITEM_H
#include <string>

struct Item
{
	int goldValue{};
	float weight{};
	std::string name{};
};

#endif