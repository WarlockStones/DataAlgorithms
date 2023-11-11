#ifndef SEARCH_H
#define SEARCH_H

class Search
{
public:
	// TODO: Return a bool like std::binary_search?
	// Binary search inspired by standard library's use of iterators
	template<typename T, typename Val>
	T BinarySearch(T array, T begin, T end, Val searchValue);
};


// TODO: Can i compare chars? Can I compare Items if I overload the == operator?
template <typename T,  typename Val>
T Search::BinarySearch(T array, T begin, T end, Val searchValue)
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

	return end; // Failure
}

#endif
