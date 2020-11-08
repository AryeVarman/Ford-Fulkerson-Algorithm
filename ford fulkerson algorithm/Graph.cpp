#include "Graph.h"

// constructor instead of MakeEmptyGraph
Graph::Graph(int i_NumberOfNodes)
{
	m_MatrixSize = i_NumberOfNodes;

	m_AdjacencyMatrix = new double*[m_MatrixSize];

	for (int i = 0; i < m_MatrixSize; i++)
	{
		m_AdjacencyMatrix[i] = new double[m_MatrixSize];
	}

	ClearGraph();
}

// copy constructor
Graph::Graph(const Graph& i_GraphToCopy)
{
	m_MatrixSize = i_GraphToCopy.m_MatrixSize;

	m_AdjacencyMatrix = new double*[m_MatrixSize];

	for (int i = 0; i < m_MatrixSize; i++)
	{
		m_AdjacencyMatrix[i] = new double[m_MatrixSize];
	}

	for (int i = 0; i < m_MatrixSize; i++)
	{
		for (int j = 0; j < m_MatrixSize; j++)
		{
			m_AdjacencyMatrix[i][j] = i_GraphToCopy.m_AdjacencyMatrix[i][j];
		}
	}
}

// d'tor
Graph::~Graph()
{
	FreeAdjacencyMatrix();
}

int Graph::GetSize() const
{
	return m_MatrixSize;
}

// set all edges to EDGE_DONT_EXIST
void Graph::ClearGraph()
{
	for (int i = 0; i < m_MatrixSize; i++)
	{
		for (int j = 0; j < m_MatrixSize; j++)
		{
			m_AdjacencyMatrix[i][j] = EDGE_DONT_EXIST;
		}
	}
}

// true if edge from i_SourceNode to i_destinationNode exist
bool Graph::IsAdjacent(int i_SourceNode, int i_destinationNode) const
{
	if (i_SourceNode > 0 && i_SourceNode <= m_MatrixSize && i_destinationNode > 0 && i_destinationNode <= m_MatrixSize)
	{
		return m_AdjacencyMatrix[i_SourceNode - 1][i_destinationNode - 1] != EDGE_DONT_EXIST;
	}

	return false;
}

// return list of all i_SourceNode ajacent nodes
List<int>* Graph::GetAdjList(int i_SourceNode) const
{
	List<int>* adjList = nullptr;

	if (i_SourceNode > 0 && i_SourceNode <= m_MatrixSize)
	{
		adjList = new List<int>;

		i_SourceNode--;

		for (int i = 0; i < m_MatrixSize; i++)
		{
			if (m_AdjacencyMatrix[i_SourceNode][i] != EDGE_DONT_EXIST)
			{
				adjList->PushBack(i + 1);
			}
		}
	}
	return adjList;
}

// add edge from i_SourceNode to i_DestinationNode in weight i_EdgeWeight
bool Graph::AddEdge(int i_SourceNode, int i_DestinationNode, double i_EdgeWeight)
{
	bool succeed = false;


	if (i_SourceNode != i_DestinationNode && // not a loop
		i_SourceNode > 0 && i_SourceNode <= m_MatrixSize && // source is within the scope
		i_DestinationNode > 0 && i_DestinationNode <= m_MatrixSize && // destination is within the scope
		m_AdjacencyMatrix[i_SourceNode - 1][i_DestinationNode - 1] == EDGE_DONT_EXIST && // not a multiple edge
		i_EdgeWeight != EDGE_DONT_EXIST && i_EdgeWeight > 0) // weight is legal
	{
		m_AdjacencyMatrix[i_SourceNode - 1][i_DestinationNode - 1] = i_EdgeWeight;
		succeed = true;
	}
	return succeed;
}

// remove edge from i_SourceNode to i_DestinationNode
void Graph::RemoveEdge(int i_SourceNode, int i_destinationNode)
{
	if (i_SourceNode > 0 && i_SourceNode <= m_MatrixSize && i_destinationNode > 0 && i_destinationNode <= m_MatrixSize)
	{
		m_AdjacencyMatrix[i_SourceNode - 1][i_destinationNode - 1] = EDGE_DONT_EXIST;
	}
}

// deallocating Adjacency Matrix
void Graph::FreeAdjacencyMatrix()
{
	for (int i = 0; i < m_MatrixSize; i++)
	{
		delete[] m_AdjacencyMatrix[i];
	}
	delete[] m_AdjacencyMatrix;

	m_MatrixSize = 0;
}

// return the weghit of edge from i_Source to i_Destination
double Graph::EdgeWeight(int i_Source, int i_Destination) const
{
	double capacity = -1;

	if (i_Source > 0 && i_Source <= m_MatrixSize && i_Destination > 0 && i_Destination <= m_MatrixSize)
	{
		capacity = m_AdjacencyMatrix[i_Source - 1][i_Destination - 1];
	}

	return capacity;
}

// return the path capacity from i_Source to i_Destination in the parent array
double Graph::FindPathCapacity(int* i_ParentArray, int i_Source, int i_Destination) const
{
	double pathCapacity = DBL_MAX;
	int currentNode = i_Destination;

	if (i_Source > 0 && i_Source <= m_MatrixSize && i_Destination > 0 && i_Destination <= m_MatrixSize)
	{
		int src;
		while (currentNode != i_Source)
		{
			if (i_ParentArray[currentNode] == (-1)) // if the path is broken then the capacity is 0
			{
				pathCapacity = 0;
				break;
			}

			src = i_ParentArray[currentNode];
			// if edge has less then path capacity, capacity then the new path capacity will be of that edge
			if (pathCapacity > m_AdjacencyMatrix[src - 1][currentNode - 1])
			{
				pathCapacity = m_AdjacencyMatrix[src - 1][currentNode - 1];
			}

			currentNode = src;
		}
	}
	else
	{
		pathCapacity = ILLEGAL_DATA;
	}
	return pathCapacity;
}

// making all ajacency matrix equals to 0
bool Graph::ZiroAllEdges()
{
	bool succeed = false;

	if (m_MatrixSize != 0)
	{
		for (int i = 0; i < m_MatrixSize; i++)
		{
			for (int j = 0; j < m_MatrixSize; j++)
			{
				m_AdjacencyMatrix[i][j] = 0.0;
			}
		}
		succeed = true;
	}

	return succeed;
}

// adding value to edge wich i_SourceName is the name of the source node name and i_DestinationName is of the destinatiion node name 
bool Graph::AddValueToEdge(int i_SourceName, int i_DestinationName, double i_ValueToAdd)
{
	bool succeed = false;

	if (i_SourceName != i_DestinationName &&
		i_SourceName > 0 && i_SourceName <= m_MatrixSize &&
		i_DestinationName > 0 && i_DestinationName <= m_MatrixSize)
	{
		m_AdjacencyMatrix[i_SourceName - 1][i_DestinationName - 1] += i_ValueToAdd;
		succeed = true;
	}

	return succeed;
}

// adding i_ValueToAdd to edge value
bool Graph::AddValueToEdge(Edge& i_EdgeToChange, double i_ValueToAdd)
{
	return AddValueToEdge(i_EdgeToChange.GetEdgeSource(), i_EdgeToChange.GetEdgeDestination(), i_ValueToAdd);
}

// setting value to edge wich i_SourceName is the name of the source node name and i_DestinationName is of the destinatiion node name 
bool Graph::SetEdgeValue(int i_SourceName, int i_DestinationName, double i_Value)
{
	bool succeed = false;

	if (i_SourceName != i_DestinationName && 
		i_SourceName > 0 && i_SourceName <= m_MatrixSize &&
		i_DestinationName > 0 && i_DestinationName <= m_MatrixSize)
	{
		m_AdjacencyMatrix[i_SourceName - 1][i_DestinationName - 1] = i_Value;
		succeed = true;
	}

	return succeed;
}

// change i_EdgeToChange weight to i_Value
bool Graph::SetEdgeValue(Edge& i_EdgeToChange, double i_Value)
{
	return SetEdgeValue(i_EdgeToChange.GetEdgeSource(), i_EdgeToChange.GetEdgeDestination(), i_Value);
}
