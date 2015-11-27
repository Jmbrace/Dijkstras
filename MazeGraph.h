#ifndef _MAZE_GRAPH_
#define _MAZE_GRAPH_
#include "MazeVertex.h"
#include <vector>
#include <map>

class MazeGraph
{
	public:
	MazeGraph( const int numOfRows, const int numOfCols, const int rowEnd, const int colEnd, const int rowStart, const int colStart);
   ~MazeGraph();
    void addVertex(const int fourBitNumber, const int row, const int col);
    void startDijkstra();
    void startAstar();
	private:
    int numOfRows, numOfCols, rowEnd, colEnd, rowStart, colStart;
	std::vector<MazeVertex*> vertexSet; 
	void dijkstra(MazeVertex *end);
    void Astar(MazeVertex *end);
};

#endif