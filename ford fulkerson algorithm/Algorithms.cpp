#pragma warning(disable: 6386)
#pragma warning(disable: 6385)
#include "Algorithms.h"

// the Ford Fulkerson algorithm: return the max flow from i_Source to i_Sink in i_Graph
double Algorithms::FordFulkerson(const Graph& i_Graph, int i_Source, int i_Sink, int* i_PathSearchMethod(const Graph&, int, int),
	Vector<int>& o_MinCutS, Vector<int>& o_MinCutT, int& o_NumberOfIterations)
{
	double maxFlow = 0;
	Graph flowGraph(i_Graph.GetSize()); // initilize the flow graph
	flowGraph.ZiroAllEdges();
	Graph residualGraph(i_Graph); // initilize the residual graph
	int* parentArray = nullptr;
	double pathCapacity;
	o_NumberOfIterations = 0; // initilize number of iterations

	if (i_Source > 0 && i_Source <= i_Graph.GetSize() && i_Sink > 0 && i_Sink <= i_Graph.GetSize())
	{
		do
		{
			parentArray = i_PathSearchMethod(residualGraph, i_Source, i_Sink);

			if (parentArray[i_Sink] != -1)
			{
				o_NumberOfIterations++;
				pathCapacity = residualGraph.FindPathCapacity(parentArray, i_Source, i_Sink);
				updateFolw(flowGraph, parentArray, i_Source, i_Sink, pathCapacity);
				updateResidualGraph(residualGraph, i_Graph, flowGraph, parentArray, i_Source, i_Sink);
			}
			else
			{
				break;
			}
			delete[] parentArray;
		} while (true);

		parentArray = BFS(residualGraph, i_Source); // finding the parent array for all nodes to define the cut

		setGraphCuts(parentArray, i_Graph.GetSize(), i_Source, o_MinCutS, o_MinCutT);

		maxFlow = calaulateFlow(flowGraph, i_Source);
	}
	else
	{
		maxFlow = ILLEGAL_DATA;
	}

	delete[] parentArray;

	return maxFlow;
}

// BFS from i_SourceNode to i_DestinationNode, return parent array
int* Algorithms::BFS(const Graph& i_Graph, int i_SourceNode, int i_DestinationNode)
{
	int arraysSize = i_Graph.GetSize() + 1;
	int* parentArray = nullptr;

	if (i_SourceNode > 0 && i_SourceNode < i_Graph.GetSize() + 1 && i_DestinationNode > 0 && i_DestinationNode < i_Graph.GetSize() + 1)
	{
		Queue<int> graphNodeQueue;
		parentArray = new int[arraysSize]; // allocate parent array
		int* distanceArray = new int[arraysSize]; // allocate distance array
		bool destinationNodeFound = false;

		// initialize distance and parent arrays
		for (int i = 0; i < i_Graph.GetSize() + 1; i++)
		{
			distanceArray[i] = POSITIVE_INFINITY; // will represent infinity
			parentArray[i] = PARENT_NOT_FOUND; // will represent that the node in place i doesnt have a known parent yet
		}

		graphNodeQueue.Enqueue(i_SourceNode); // enqueue source node
		distanceArray[i_SourceNode] = 0; // set distance source node to 0

		int currentNode;
		List<int>* ajacentList = nullptr;

		while (graphNodeQueue.IsEmpty() == false && destinationNodeFound == false)
		{
			currentNode = graphNodeQueue.Dequeue(); // dequeue next node in queue

			ajacentList = i_Graph.GetAdjList(currentNode);
			int adjacentNode;

			while (ajacentList->IsEmpty() == false)
			{
				adjacentNode = ajacentList->GetHead()->GetData();
				ajacentList->DeleteHead();

				if (distanceArray[adjacentNode] == POSITIVE_INFINITY)
				{
					distanceArray[adjacentNode] = distanceArray[currentNode] + 1; // set the distance
					parentArray[adjacentNode] = currentNode; // set the parent
					graphNodeQueue.Enqueue(adjacentNode); // enqueue the ajacent node
				}

				if (adjacentNode == i_DestinationNode) // if the destination node was found we will stop the search
				{
					destinationNodeFound = true;
					break;
				}
			}
			delete ajacentList;
		}

		delete[] distanceArray; // free distance array
	}

	return parentArray;
}

// BFS from i_SourceNode to all nodes, return parent array
int* Algorithms::BFS(const Graph& i_Graph, int i_SourceNode)
{
	int* parentArray = nullptr;

	if (i_SourceNode > 0 && i_SourceNode < i_Graph.GetSize() + 1)
	{
		Queue<int> graphNodeQueue;
		parentArray = new int[i_Graph.GetSize() + 1]; // allocate parent array
		int* distanceArray = new int[i_Graph.GetSize() + 1]; // allocate distance array

		// initialize distance and parent arrays
		for (int i = 0; i < i_Graph.GetSize() + 1; i++)
		{
			distanceArray[i] = POSITIVE_INFINITY; // will represent infinity
			parentArray[i] = PARENT_NOT_FOUND; // will represent that the node in place i doesnt have a known parent yet
		}

		graphNodeQueue.Enqueue(i_SourceNode); // enqueue source node
		distanceArray[i_SourceNode] = 0; // set distance source node to 0

		int currentNode;
		List<int>* ajacentList = nullptr;

		while (graphNodeQueue.IsEmpty() == false)
		{
			currentNode = graphNodeQueue.Dequeue(); // dequeue next node in queue

			ajacentList = i_Graph.GetAdjList(currentNode);
			int adjacentNode;

			while (ajacentList->IsEmpty() == false)
			{
				adjacentNode = ajacentList->GetHead()->GetData();
				ajacentList->DeleteHead();

				if (distanceArray[adjacentNode] == POSITIVE_INFINITY)
				{
					distanceArray[adjacentNode] = distanceArray[currentNode] + 1; // set the distance
					parentArray[adjacentNode] = currentNode; // set the parent
					graphNodeQueue.Enqueue(adjacentNode); // enqueue the ajacent node
				}
			}
			delete ajacentList;
		}
		delete[] distanceArray; // free distance array
	}

	return parentArray;
}

// find maximal weighted array from i_SourceNode to i_DestinationNode, return parent array
int* Algorithms::DijkstraMaximalWeghit(const Graph& i_Graph, int i_SourceNode, int i_DestinationNode)
{
	int* parentArray = nullptr; // parent array for the path from source to destination
	double* weightArray = nullptr; // weight array for the maximal profit in each dequeue
	HeapPair<double, int>** pointerToGraphNodeArray = nullptr; // pointer to the queue nodes

	if (i_SourceNode > 0 && i_SourceNode < i_Graph.GetSize() + 1 && i_DestinationNode > 0 && i_DestinationNode < i_Graph.GetSize() + 1)
	{
		intilizeArrayForHeap(i_Graph.GetSize(), i_SourceNode, pointerToGraphNodeArray);
		MaxBinaryHeap<double, int> binaryHeap(&(pointerToGraphNodeArray[1]), i_Graph.GetSize()); // create and build heap
		parentArray = new int[(i_Graph.GetSize() + 1)]; // allocate parent array
		weightArray = new double[(i_Graph.GetSize() + 1)]; // allocate weight array

		for (int i = 1; i < i_Graph.GetSize() + 1; i++)
		{
			parentArray[i] = PARENT_NOT_FOUND; // will represent that the node in place i doesnt have a known parent yet
			weightArray[i] = 0;
		}

		weightArray[i_SourceNode] = DBL_MAX; // no limit from source
		int currentNode; // in first iteration currentNode will be the source for it initilzed to 1 and the rest for 0
		List<int>* ajacentList = nullptr;

		while (binaryHeap.IsEmpty() == false)
		{
			currentNode = binaryHeap.DeleteMax();

			if (currentNode == i_DestinationNode)
			{
				break;
			}

			ajacentList = i_Graph.GetAdjList(currentNode);
			int ajacentNode;

			while (ajacentList->IsEmpty() == false)
			{
				ajacentNode = ajacentList->GetHead()->GetData();
				ajacentList->DeleteHead();

				if (weightArray[ajacentNode] < weightArray[currentNode] &&
					weightArray[ajacentNode] < i_Graph.EdgeWeight(currentNode, ajacentNode))
				{
					weightArray[ajacentNode] = Min(weightArray[currentNode], i_Graph.EdgeWeight(currentNode, ajacentNode));
					parentArray[ajacentNode] = currentNode;
					binaryHeap.IncreaseKey(pointerToGraphNodeArray[ajacentNode], weightArray[ajacentNode]);
				}
			}
			delete ajacentList;
		}
	}

	if (pointerToGraphNodeArray != nullptr)
	{
		for (int i = 1; i < i_Graph.GetSize() + 1; i++)
		{
			delete pointerToGraphNodeArray[i];
		}
	}
	delete[] pointerToGraphNodeArray;
	delete[] weightArray;

	return parentArray;
}

// gets parent array and return graph cuts in o_MinCutS and o_MinCutT when is i_Source s
void Algorithms::setGraphCuts(int* i_ParrentArray, int i_GraphSize, int i_Source, Vector<int>& o_MinCutS, Vector<int>& o_MinCutT)
{
	for (int i = 1; i <= i_GraphSize; i++)
	{
		if (i_ParrentArray[i] != (-1) || i == i_Source)
		{
			o_MinCutS.PushBack(i);
		}
		else
		{
			o_MinCutT.PushBack(i);
		}
	}
}

// updating the flow value from i_Source to i_Destination in the path given by the parent array
bool Algorithms::updateFolw(Graph& i_FlowGraph, int* i_parentArray, int i_Source, int i_Destination, double i_ValueToAdd)
{
	bool succeed = false;
	int currentNode = i_Destination;
	int src;

	if (i_Source > 0 && i_Source <= i_FlowGraph.GetSize() && i_Destination > 0 && i_Destination <= i_FlowGraph.GetSize())
	{
		succeed = true;

		while (currentNode != i_Source)
		{
			src = i_parentArray[currentNode];

			i_FlowGraph.AddValueToEdge(src, currentNode, i_ValueToAdd);

			double srcToCurrentNode = i_FlowGraph.EdgeWeight(src, currentNode);
			i_FlowGraph.SetEdgeValue(currentNode, src, srcToCurrentNode * (-1));

			currentNode = src;
		}
	}

	return succeed;
}

// updating the residual graph on path from i_Source to i_Destination in the path given by the parent array
bool Algorithms::updateResidualGraph(Graph& i_ResidualGraph, const Graph& i_RegularGraph,
	const Graph& i_FlowGraph, int* i_parentArray, int i_Source, int i_Destination)
{
	bool succeed = false;
	int currentNode = i_Destination;
	int src;

	if (i_ResidualGraph.GetSize() == i_FlowGraph.GetSize() && i_ResidualGraph.GetSize() == i_RegularGraph.GetSize() &&
		i_Source > 0 && i_Source <= i_ResidualGraph.GetSize() && i_Destination > 0 && i_Destination <= i_ResidualGraph.GetSize())
	{
		succeed = true;

		while (currentNode != i_Source)
		{
			src = i_parentArray[currentNode];

			i_ResidualGraph.SetEdgeValue(src, currentNode,
				i_RegularGraph.EdgeWeight(src, currentNode) - i_FlowGraph.EdgeWeight(src, currentNode));

			i_ResidualGraph.SetEdgeValue(currentNode, src,
				i_RegularGraph.EdgeWeight(currentNode, src) - i_FlowGraph.EdgeWeight(currentNode, src));

			currentNode = src;
		}
	}

	return succeed;
}

// calculating flow on all outgoing edges from i_Source
double Algorithms::calaulateFlow(const Graph& i_FlowGraph, int i_Source)
{
	double flow = 0.0;

	if (i_Source > 0 && i_Source <= i_FlowGraph.GetSize())
	{
		List<int>* ajacentList = i_FlowGraph.GetAdjList(i_Source);
		int ajacentNode;

		while (ajacentList->IsEmpty() == false)
		{
			ajacentNode = ajacentList->GetHead()->GetData();
			ajacentList->DeleteHead();
			flow += i_FlowGraph.EdgeWeight(i_Source, ajacentNode);
		}

		delete ajacentList;
	}
	else
	{
		flow = ILLEGAL_DATA;
	}

	return flow;
}

// intilize the Array For build Heap algorithm
bool Algorithms::intilizeArrayForHeap(int i_NumberOfNodes, int i_Source, HeapPair<double, int>**& o_PointersToPairArray)
{
	bool succeed = false;
	if (i_Source > 0 && i_Source <= i_NumberOfNodes)
	{
		succeed = true;

		o_PointersToPairArray = new HeapPair<double, int> *[i_NumberOfNodes + 1];

		for (int i = 1; i <= i_NumberOfNodes; i++)
		{
			o_PointersToPairArray[i] = new HeapPair<double, int>(0, i, (i - 1));
		}

		o_PointersToPairArray[i_Source]->SetKey(1); // give priority to the source
	}
	return succeed;
}

double Algorithms::Min(double i_First, double i_Second)
{
	double minValue;

	if (i_First <= i_Second)
	{
		minValue = i_First;
	}
	else
	{
		minValue = i_Second;
	}

	return minValue;
}