#ifndef SORT_H
#define SORT_H

class Sort {
public:
	// Sort an array of integers using Merge Sort algorithm
	void BottomUpMergeSort(int* arrayToSort, int* workArray, int maxSize);

private:
	void BottomUpMerge(int* arrayToSort, int left, int right, int end, int* workArray);
	void CopyArray(int* workArray, int* arrayToSort, int maxSize);
};


#endif