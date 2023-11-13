#include "Measurements.hpp"
#include "Tree.h"

int main()
{
    // Measurements measure;
    // measure.MeasureBinarySearch();

    Tree tree;

	tree.InsertValue(1);
	tree.InsertValue(2);
	tree.InsertValue(3);
	tree.InsertValue(4);
	tree.InsertValue(5);

	tree.TraverseInOrder();

	tree.Delete();

    return 0;
}
