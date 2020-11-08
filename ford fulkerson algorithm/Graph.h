#ifndef __Graph_H
#define __Graph_H

#include"Queue.h"
#include"MaxBinaryHeap.h"
#include"Edge.h"
#include<limits>

#define EDGE_DONT_EXIST 0.0
#define POSITIVE_INFINITY -1
#define PARENT_NOT_FOUND -1
#define ILLEGAL_DATA -1

class Graph
{
private:
	double** m_AdjacencyMatrix;
	int		m_MatrixSize;

public:
	Graph(int i_NumberOfNodes);
	Graph(const Graph& i_GraphToCopy);
	~Graph();

	int GetSize() const;
	void ClearGraph();

	bool IsAdjacent(int i_SourceNode, int i_destinationNode) const;
	List<int>* GetAdjList(int i_SourceNode) const;
	bool AddEdge(int i_SourceNode, int i_destinationNode, double i_EdgeCapacity);
	void RemoveEdge(int i_SourceNode, int i_destinationNode);
	void FreeAdjacencyMatrix();

	double EdgeWeight(int i_Source, int i_Destination) const;
	double FindPathCapacity(int* i_ParentArray, int i_Source, int i_Destination) const;

	bool ZiroAllEdges();
	bool AddValueToEdge(int i_SourceName, int i_DestinationName, double i_ValueToAdd);
	bool AddValueToEdge(Edge& i_EdgeToChange, double i_ValueToAdd);

	bool SetEdgeValue(int i_SourceName, int i_DestinationName, double i_Value);
	bool SetEdgeValue(Edge& i_EdgeToChange, double i_Value);
};
#endif // !__Graph_H