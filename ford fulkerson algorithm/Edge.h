#ifndef __Edge_H
#define __Edge_H

class Edge
{
private:
	const int m_EdgeSource;
	const int m_EdgeDestination;
	double m_EdgeCapacity;

public:
	Edge(int i_EdgeSource, int i_EdgeDestination, double i_EdgeCapacity);

	int GetEdgeSource();
	int GetEdgeDestination();
	double GetEdgeCapacity();

	bool SetEdgeCapacity(double i_EdgeCapacity);

	bool operator==(const Edge& i_Edge);
	bool operator>(const Edge& i_Edge);
	bool operator>=(const Edge& i_Edge);
	bool operator<(const Edge& i_Edge);
	bool operator<=(const Edge& i_Edge);
	void operator++();
	void operator+(int i_CapacityToAdd);
	void operator-(int i_CapacityToAdd);
};
#endif // !__EdgeListNode_H