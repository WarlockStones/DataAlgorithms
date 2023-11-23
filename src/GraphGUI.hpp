#ifndef GRAPHGUI_H
#define GRAPHGUI_H
#include <string>
#include <vector>
#include "Graph.hpp"

// Class that draws graphs and highlights nodes in graph. It does not care, it just draws nodes.
class GraphGUI
{
public:
	// Initialize base graph from file
	static void Initialize(const char* path);

	// Change every instance of character from 'from' to 'to'
	static void ReplaceChar(char from, char to);

	// Print the whole graph
	static void PrintLines();

	// Highlight characters for a "frame", before returning to the original characters
	static void Highlight(std::vector<Vector2>& targets);

	// Highlights current char as @ then when traversing change @ to o
	static void PrintTraversal(std::vector<Vector2>& tilesToHighlight);
	static void PrintTraversal(Vector2& tileToHighlight);
	void Pause();

	inline static bool enabled = true;

private:
	static void WaitForInput();
	inline static char highlightChar = '@';
	inline static char visitedChar = 'o';

	// Each line is a string. To get pos 3.5 we get lines[5] > char 3
	inline static std::vector<std::string> lines;
};

#endif
