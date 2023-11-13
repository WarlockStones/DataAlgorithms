#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

class Search
{
public:
	// Binary search inspired by standard library's use of iterators
	template <typename Iter, typename Val>
	Iter BinarySearch(Iter array, Iter begin, Iter end, Val searchValue);

	// Binary search using std::lower_bound
	template <typename Iter, typename Val>
	Iter BinarySearchLowBound(Iter begin, Iter end, Val searchValue);

	// std::binary_search(begin, end, value);
};


// TODO: Can i compare chars? Can I compare Items if I overload the == operator?
template <typename Iter, typename Val>
Iter Search::BinarySearch(Iter array, Iter begin, Iter end, Val searchValue)
{
	// Get index number from pointer
	auto beginIndex = begin - &array[0];
	auto endIndex = end - &array[0];
	Val min = beginIndex;
	Val max = endIndex;
	while (min <= max)
	{
		int mid = min + (max - min) / 2; // Middle index

		if (array[mid] > searchValue)
			max = mid - 1;
		else if (array[mid] < searchValue)
			min = mid + 1;
		else // We hit the spot!
			return &array[mid];
	}

	// End is past-the-last element. It will be garbage data. Compare != End
	return end; // Failure
}


template <typename Iter, typename Val>
Iter Search::BinarySearchLowBound(Iter begin, Iter end, Val searchValue)
{
	Iter i = std::lower_bound(begin, end, searchValue);

	if (i != end && !(searchValue < *i))
		return i;
	return end;
}


#endif
