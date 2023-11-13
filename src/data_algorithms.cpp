#include "Measurements.hpp"
#include "Tree.h"

int main()
{
    // Measurements measure;
    // measure.MeasureBinarySearch();

    Tree tree;
    tree.InsertValue(5);
    tree.InsertValue(1);
    tree.InsertValue(4);
    tree.InsertValue(7);
    tree.InsertValue(8);
    tree.InsertValue(0);
    tree.InsertValue(2);
    tree.InsertValue(2);
    tree.InsertValue(2);
    tree.InsertValue(3);

    tree.TraverseInOrder(); // Traverse
}
