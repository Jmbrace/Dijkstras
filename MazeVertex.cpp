#include "MazeVertex.h"
#include <iostream>

MazeVertex::MazeVertex(const int row, const int col, const int fourBitNumber)
{
	this->row = row;
	this->col = col;
	this->fourBitNumber = fourBitNumber;
}

MazeVertex::MazeVertex()
{

}

MazeVertex::~MazeVertex()
{

}

//If there is not a wall between two vertices, there exist an edge.
void MazeVertex::setAdjacencyList(const int numOfCols, const int numOfRows)
{
	if((fourBitNumber & 1)==0)//Then an edge exists between this vertex and the vertex below it
	{
		if(row!=(numOfRows-1))//The entrance an exit of the maze has no wall, we must not treat this as an edge 
			adjList.push_back(label+numOfCols);//the index of given vertex plus column number is index of below vertex
	}
	if((fourBitNumber & 2)==0)//Then an edge exists between this vertex and the vertex to the right of it
	{
		if(col!=(numOfCols-1))//The entrance an exit of the maze has no wall, we must not treat this as an edge 
			adjList.push_back(label+1);//the index of given vertex plus 1 is index of right vertex
	}
	if((fourBitNumber & 4)==0)//Then an edge exists between this vertex and the vertex above it
	{
		if(row!=0)//The entrance an exit of the maze has no wall, we must not treat this as an edge 
			adjList.push_back(label-numOfCols);//the index of given vertex minus column number is index of above vertex
	}
	if((fourBitNumber & 8)==0)//Then an edge exists between this vertex and the vertex to the left of it
	{
		if(col!=0)//The entrance an exit of the maze has no wall, we must not treat this as an edge 
			adjList.push_back(label-1);//the index of given vertex minus 1 is index of left vertex
	}
}