#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "MazeGraph.h"

int main(int numOfArgs, char** args)
{
	std::fstream fs;
	std::string mazeFileFlag = "-m";
	std::string astarFlag = "-Astar";
	std::string fileName;
	int numOfRows = 0;
	int numOfCols = 0;
	int column = -1;
	int row = -1;
	int colStart = -1;
	int colEnd = -1;
	int rowStart = -1;
	int rowEnd = -1;
	int fourBitEdgeVal = -1;

	if(numOfArgs<3)
	{
		std::cout << "Please provide a maze text file." << std::endl;
		return 1;
	}
	
	if(std::strncmp(args[1], mazeFileFlag.c_str(), 3)!=0)
	{
		std::cout << "Please use the flag -m before the file name." << std::endl;
		return 2;
	}
	fileName = args[2];
	fs.open(fileName);
	if(fs.is_open())
	{
		fs >> numOfRows;//read the row number
		fs >> numOfCols;//read the column number
		fs >> rowStart;
		fs >> colStart;
		fs >> rowEnd;
		fs >> colEnd;

		MazeGraph g(numOfRows, numOfCols, rowEnd, colEnd, rowStart, colStart);//Create Graph representation of maze

		for(int r = 0; r < numOfRows; r++)
		{
			for(int c = 0; c < numOfCols; c++)
			{
				fs >> fourBitEdgeVal;
				g.addVertex(fourBitEdgeVal, r, c);
			}
		}

		if(numOfArgs>3)
		{
			if(std::strncmp(args[3], astarFlag.c_str(), 7)==0)
			{
				std::cout << "A* executed." << std::endl;
				g.startAstar();
			}
			else 
			{
				std::cout << "Invalid argument. Do not provide an argument after the file to execute Dijkstras." << std::endl;
				std::cout << "Or use the flag '-Astar' to execute A*" << std::endl;
			}
		}
		else
		{
			std::cout << "Dijkstra's executed." << std::endl;
			g.startDijkstra();
		}
	}
	else
	{
		std::cout << "Something went wrong with opening the file." << std::endl;
		return 3;
	}
	

	return 0;
}