#include "Measurements.hpp"
#include "Tree.h"

int main()
{
	// Measurements measure;
	// measure.MeasureBinarySearch();

	Tree tree;

  // https://en.wikipedia.org/wiki/File:Binary_search_tree.svg 
  /*
           8
         /   \
        3     10
       / \      \
      1   6      14
         / \    /
        4   7  13
  */
	tree.InsertValue(8); // Root

  // Right sub-nodes
  tree.InsertValue(10);
  tree.InsertValue(14);
  tree.InsertValue(13);

  // Left sub-nodes
  tree.InsertValue(3);
  tree.InsertValue(1);
  tree.InsertValue(6);
  tree.InsertValue(4);
  tree.InsertValue(7);

  tree.TraverseBreadthFirst();

	return 0;
}
