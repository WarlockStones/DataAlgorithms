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

	tree.TraverseInOrder();

	tree.InsertValue(11);
	tree.InsertValue(12);
	tree.InsertValue(13);

	tree.TraverseInOrder();

    return 0;
}
