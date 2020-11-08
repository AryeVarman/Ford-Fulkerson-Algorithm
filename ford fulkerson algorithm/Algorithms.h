#ifndef __Algorithms_H
#define __Algorithms_H

#include "Graph.h"

class Algorithms
{
public:
	static double FordFulkerson(const Graph& i_Graph, int i_Source, int i_Sink, int* i_PathSearchMethod(const Graph&, int, int),
		Vector<int>& o_MinCutS, Vector<int>& o_MinCutT, int& o_NumberOfIterations);

	static int* BFS(const Graph& i_Graph, int i_SourceNode, int i_DestinationNode);
	static int* BFS(const Graph& i_Graph, int i_SourceNode);

	static int* DijkstraMaximalWeghit(const Graph& i_Graph, int i_SourceNode, int i_DestinationNode);

private:
	static void setGraphCuts(int* i_ParrentArray, int i_GraphSize, int i_Source, Vector<int>& o_MinCutS, Vector<int>& o_MinCutT);
	static bool updateFolw(Graph& i_FlowGraph, int* i_parentArray, int i_Source, int i_Destination, double i_ValueToAdd);
	static bool updateResidualGraph(Graph& i_ResidualGraph, const Graph& i_RegularGraph, const Graph& i_FlowGraph,
		int* i_parentArray, int i_Source, int i_Destination);
	static double calaulateFlow(const Graph& i_FlowGraph, int i_Source);
	static bool intilizeArrayForHeap(int i_NumberOfNodes, int i_Source, HeapPair<double, int>**& o_PointersToPairArray);
	static double Min(double i_First, double i_Second);
};
#endif // !__Algorithms_H