#include "Sort.hpp"
#include <algorithm>

// C approach from Wikipeda
// "Sub-list" aka Run. Is a part of the array we are currently working with. "Partitioned" Array.
void Sort::BottomUpMergeSort(int* arrayToSort, int* workArray, int maxSize)
{
	// Make successively longer sorter "sub-lists" of length 2, 4, 8... until array is sorted
	for (int width = 1; width < maxSize; width = 2 * width) {
		for (int i = 0; i < maxSize; i = i + 2 * width) {
			BottomUpMerge(arrayToSort, i, std::min(i + width, maxSize), std::min(i + 2 * width, maxSize), workArray);
		}

		// workArray is full of "sub-lists". So A will be full of sorted runs of length 2*width.
		CopyArray(workArray, arrayToSort, maxSize);
	}
}

void Sort::BottomUpMerge(int* arrayToSort, int left, int right, int end, int* workArray)
{
	int i = left, j = right; // "Arrows" pointing at what to compare. We move across sub-list
	// k = a check for while there are elements in the sub-list left to compare
	for (int k = left; k < end; ++k) // The section of the sub-list to compare
	{
		// If left sub-list exists && right sub(j) does not exist, or left hand value is <= value of right(j) "arrow"
		if (i < right && (j >= end || arrayToSort[i] <= arrayToSort[j]))
		{
			workArray[k] = arrayToSort[i];
			++i; // Just move index[i] so move "arrow" to the right
		}
		else
		{
			workArray[k] = arrayToSort[j];
			++j; // Just move index[j] so move "arrow" to the right
		}
	}
}

void Sort::CopyArray(int* workArray, int* arrayToSort, int maxSize)
{
	for (int i = 0; i < maxSize; ++i)
	{
		arrayToSort[i] = workArray[i];
	}
}
