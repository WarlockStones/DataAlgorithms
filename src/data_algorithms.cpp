#include "Measurements.hpp"
#include "Tree.h"

int main()
{
    // Measurements measure;
    // measure.MeasureBinarySearch();

    Tree tree;

	tree.InsertValue(80);
	tree.InsertValue(13);
	tree.InsertValue(15);
	tree.InsertValue(12);

	tree.TraverseInOrder();

	tree.Delete();
	tree.TraverseInOrder();

	tree.InsertValue(2);
	tree.InsertValue(1);
	tree.InsertValue(3);

	tree.TraverseInOrder();

    return 0;
}
