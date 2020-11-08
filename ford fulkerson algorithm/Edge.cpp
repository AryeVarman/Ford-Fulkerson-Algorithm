#include "Edge.h"

Edge::Edge(int i_EdgeSource, int i_EdgeDestination, double i_EdgeCapacity) :
	m_EdgeSource(i_EdgeSource), m_EdgeDestination(i_EdgeDestination)
{
	m_EdgeCapacity = i_EdgeCapacity;
}

int Edge::GetEdgeSource()
{
	return m_EdgeSource;
}

int Edge::GetEdgeDestination()
{
	return m_EdgeDestination;
}

double Edge::GetEdgeCapacity()
{
	return m_EdgeCapacity;
}

bool Edge::SetEdgeCapacity(double i_EdgeCapacity)
{
	bool succeed = false;

	if (i_EdgeCapacity > 0)
	{
		m_EdgeCapacity = i_EdgeCapacity;
		succeed = true;
	}

	return succeed;
}

bool Edge::operator==(const Edge& i_Edge)
{
	return m_EdgeCapacity == i_Edge.m_EdgeCapacity;
}

bool Edge::operator>(const Edge& i_Edge)
{
	return m_EdgeCapacity > i_Edge.m_EdgeCapacity;
}

bool Edge::operator>=(const Edge& i_Edge)
{
	return m_EdgeCapacity >= i_Edge.m_EdgeCapacity;
}

bool Edge::operator<(const Edge& i_Edge)
{
	return m_EdgeCapacity < i_Edge.m_EdgeCapacity;
}

bool Edge::operator<=(const Edge& i_Edge)
{
	return m_EdgeCapacity <= i_Edge.m_EdgeCapacity;

}

void Edge::operator++()
{
	m_EdgeCapacity += 1;
}

void Edge::operator+(int i_CapacityToAdd)
{
	m_EdgeCapacity += i_CapacityToAdd;
}

void Edge::operator-(int i_CapacityToAdd)
{
	m_EdgeCapacity -= i_CapacityToAdd;
}
