#include "MazeGraph.h"
#include <iostream>
#include <queue>

MazeGraph::MazeGraph(const int numOfRows, const int numOfCols, const int rowEnd, const int colEnd, const int rowStart, const int colStart)
{
	this->numOfRows = numOfRows;
	this->numOfCols = numOfCols;
	this->rowEnd = rowEnd;
	this->colEnd = colEnd;
	this->rowStart = rowStart;
	this->colStart = colStart;
}


MazeGraph::~MazeGraph()
{
	for(int i = 0; i < vertexSet.size(); i++)
		delete vertexSet[i];
}

void MazeGraph::addVertex(const int fourBitNumber, const int row, const int col)
{
	MazeVertex *vertex =  new MazeVertex(row, col, fourBitNumber);
	vertex->label = vertexSet.size();
	vertexSet.push_back(vertex);
	vertex->setAdjacencyList(numOfCols, numOfRows);
}

void MazeGraph::startDijkstra() const
{
	MazeVertex* end = vertexSet[(rowEnd*numOfRows+colEnd)];
	dijkstra(end);

	MazeVertex* start = vertexSet[(rowStart*numOfRows+colStart)];
	while(start->previous!=NULL)
	{
		std::cout<< start->previous->row << " " << start->previous->col << std::endl;
		start = start->previous;
	}
}

void MazeGraph::startAstar() const
{
	MazeVertex* end = vertexSet[(rowEnd*numOfRows+colEnd)];
	Astar(end);

	MazeVertex* start = vertexSet[(rowStart*numOfRows+colStart)];
	while(start->previous!=NULL)
	{
		std::cout<< start->previous->row << " " << start->previous->col << std::endl;
		start = start->previous;
	}
}

void MazeGraph::dijkstra(MazeVertex *end)
{
	std::priority_queue<MazeVertex*, std::vector<MazeVertex*>, compareVertices> pq;
	for(int i = 0; i < vertexSet.size(); i ++)
	{
		vertexSet[i]->distance = INT_MAX;
		vertexSet[i]->traversed = false;
		vertexSet[i]->previous = NULL;
		pq.push(vertexSet[i]);
	}

	end->distance = 0;
	pq.push(end);

	while(!pq.empty())
	{
		MazeVertex* u = pq.top();
		pq.pop();
		
		if(u->distance == INT_MAX)
			break;
		if(u->traversed)
			continue;

		u->traversed = true;

		for(std::list<int>::iterator it = u->adjList.begin(); it!= u->adjList.end(); it++)
		{
			if(!((vertexSet[*it])->traversed))
			{
				if(u->distance+1< (vertexSet[*it])->distance)
				{
					(vertexSet[*it])->distance = u->distance+1;
					(vertexSet[*it])->previous = u;
					pq.push(vertexSet[*it]);
				}

			}
		}

	}
}

void MazeGraph::Astar(MazeVertex *end)
{
	std::priority_queue<MazeVertex*, std::vector<MazeVertex*>, compareVertices> pq;
	for(int i = 0; i < vertexSet.size(); i ++)
	{
		vertexSet[i]->distance = INT_MAX;
		vertexSet[i]->traversed = false;
		vertexSet[i]->previous = NULL;
		pq.push(vertexSet[i]);
	}

	end->distance = 0;
	pq.push(end);

	while(!pq.empty())
	{
		MazeVertex* u = pq.top();
		pq.pop();
		
		if(u->distance == INT_MAX)
			break;
		if(u->traversed)
			continue;

		u->traversed = true;

		for(std::list<int>::iterator it = u->adjList.begin(); it!= u->adjList.end(); it++)
		{
			if(!((vertexSet[*it])->traversed))
			{
				if(u->distance+1< (vertexSet[*it])->distance)
				{
					int heuristic = (vertexSet[*it]->row-end->row)+(vertexSet[*it]->col-end->col);//The Astar heuristic
					(vertexSet[*it])->distance = u->distance+1 + heuristic;
					(vertexSet[*it])->previous = u;
					pq.push(vertexSet[*it]);
				}

			}
		}

	}
}

