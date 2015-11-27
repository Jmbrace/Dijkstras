#ifndef _MAZE_VERTEX_
#define _MAZE_VERTEX_
#include <list>

class MazeVertex
{
	friend class MazeGraph;
	friend class compareVertices;
	public:
	MazeVertex(const int row, const int col, const int fourBitNumber);
	MazeVertex();
   ~MazeVertex();

	private:
	void setAdjacencyList(const int numOfCols, const int numOfRows);
	std::list<int> adjList; // Each vertex maintatins a list of integers where each integer is the index of an adjacent vertex in the MazeGraph member vector called VertexSet
	int distance;
	int label; //an integer label for a vertex, identical to to its position in the MazeGraph member vector called vertexSet
	bool traversed;
	MazeVertex* previous;
	int row;
	int col;
	int fourBitNumber;
};

class compareVertices //comparison class used for the priority queue 
{
	public:
	bool operator() (MazeVertex const *v, MazeVertex const *u) const
	{
		return v->distance >= u->distance;
	}
};
#endif