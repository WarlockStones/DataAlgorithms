#include "GraphGUI.hpp"
#include <fstream>
#include <iostream>

/* Initialize the base graph. Adds lines from file to variable graphLines */
void GraphGUI::Initialize(const char* path)
{
	std::string line;
	std::ifstream file(path);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			lines.push_back(line);
			std::cout << "Reading line\n";
		}
		std::cout << "line size = " << lines.size() << '\n';
		file.close();
	}
	else
	{
		std::cout << "GraphGUI: Unable to open file! '" << path << "'\n";
		return;
	}
}

void GraphGUI::ReplaceChar(char from, char to)
{
	if (lines.size() < 1)
	{
		std::cout << "GraphGUI: Lines are empty. No char to replace.\n";
		return;
	}

	for (std::string& line : lines)
	{
		for (char& c : line)
		{
			if (c == from)
				c = to;
		}
	}
}

void GraphGUI::PrintLines()
{
	for (auto line : lines)
	{
		std::cout << line << '\n';
	}
	std::cout << '\n'; // Line-break after whole gui has been printed
}

void GraphGUI::PrintTraversal(std::vector<Vector2>& tilesToHighlight)
{
	ReplaceChar(highlightChar, visitedChar);
	for (auto pos : tilesToHighlight)
	{
		std::string& line = lines[pos.y];
		line[pos.x] = highlightChar;
	}
}

void GraphGUI::PrintTraversal(Vector2& tileToHighlight)
{
	ReplaceChar(highlightChar, visitedChar);
	std::string& line = lines[tileToHighlight.y];
	line[tileToHighlight.x] = highlightChar;

	PrintLines();
	// Pause and wait for input
	WaitForInput();
}

void GraphGUI::WaitForInput()
{
	static std::string str = "";
	static int timesToSkip = 0;
	static int skips = 0;
	std::cout << "Times to skip = " << timesToSkip <<". (enter <number> to skip)"<<'\n';

	if (skips < 1)
	{
		// Pause and read each char
		while (char in = std::cin.get())
		{
			skips = timesToSkip; // To keep it refreshed each pause
			if (in == '\n') // Break if <enter> is pressed
			{
				std::cout << str << '\n';
				if (!str.empty())
				{
					timesToSkip = std::stoi(str);
					skips = timesToSkip;
				}
				str = "";
				break;
			}
			// If in is number add it to str
			if (std::isdigit(in))
			{
				str += in;
			}
		}
	}
	else
	{
		--skips;
	}
}
