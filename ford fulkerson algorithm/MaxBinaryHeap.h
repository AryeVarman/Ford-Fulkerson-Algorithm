#ifndef __MaxBinaryHeap_H
#define __MaxBinaryHeap_H

#include"HeapPair.h"
#include"Vector.h"

// class S hould have	||   	Class T should have
// operator==			||   	operator=
// operator>=			||   
// operator<=			||   
// operator>			||   
// operator<			||   
// operator=			||   


template <class S, class T>
class MaxBinaryHeap
{
private:
	Vector<HeapPair<S, T>*> m_Vector;
	int m_Count;

public:
	MaxBinaryHeap(const Vector<HeapPair<S, T>*>& i_Vector); // Build Head
	MaxBinaryHeap(HeapPair<S, T>** i_Arr, int i_Size); // Build Head

	bool IsEmpty();
	bool IncreaseKey(int i_Place, S i_NewKey);
	bool IncreaseKey(HeapPair<S, T>* i_nodeToIncrease, S i_NewKey);
	T Max();
	T DeleteMax();

private:
	void buildHeap();
	void fixHeap(int i_NodePlace);
	int left(int i_PlaceInHeap);
	int right(int i_PlaceInHeap);
	int parent(int i_PlaceInHeap);
	void swap(int i_First, int i_Second);
};
#endif // !__MaxBinaryQueue_H

template<class S, class T>
inline MaxBinaryHeap<S, T>::MaxBinaryHeap(const Vector<HeapPair<S, T>*>& i_Vector) : m_Vector(i_Vector)
{
	m_Count = i_Vector.GetCount();

	buildHeap();
}

template<class S, class T>
inline MaxBinaryHeap<S, T>::MaxBinaryHeap(HeapPair<S, T>** i_Arr, int i_Size) :m_Vector(i_Arr, i_Size), m_Count(i_Size)
{
	buildHeap();
}

// return the maximum value and delete it from the heap
template<class S, class T>
inline T MaxBinaryHeap<S, T>::DeleteMax()
{
	if (m_Count < 1)
	{
		throw m_Count;
	}

	T max = m_Vector[0]->GetData();
	m_Count--;
	m_Vector[0] = m_Vector[m_Count];
	m_Vector[0]->SetPlaceInHeap(0);
	fixHeap(0);

	return max;
}

// check if heap is empty
template<class S, class T>
inline bool MaxBinaryHeap<S, T>::IsEmpty()
{
	return m_Count == 0;
}

// increase the key of the element in i_Place to i_NewKey
template<class S, class T>
inline bool MaxBinaryHeap<S, T>::IncreaseKey(int i_Place, S i_NewKey)
{
	bool succeed = true;

	if (i_Place < 0 || i_Place >= m_Count || i_NewKey <= m_Vector[i_Place]->GetKey())
	{
		bool succed = false;
	}
	else
	{
		m_Vector[i_Place]->SetKey(i_NewKey);

		while (i_Place >= 1 && m_Vector[parent(i_Place)]->GetKey() < m_Vector[i_Place]->GetKey())
		{
			swap(i_Place, parent(i_Place));
			i_Place = parent(i_Place);
		}
	}

	return succeed;
}

// increase the key of the element i_nodeToIncrease to i_NewKey
template<class S, class T>
inline bool MaxBinaryHeap<S, T>::IncreaseKey(HeapPair<S, T>* i_nodeToIncrease, S i_NewKey)
{
	return IncreaseKey(i_nodeToIncrease->GetPlaceInHeap(), i_NewKey);
}

// return the maximum value without deleting it
template<class S, class T>
inline T MaxBinaryHeap<S, T>::Max()
{
	if (m_Count > 0)
	{
		return m_Vector[0]->GetData();
	}
	throw m_Count;
}

// build head with Floid algorithm
template<class S, class T>
inline void MaxBinaryHeap<S, T>::buildHeap()
{
	for (int i = (m_Count / 2) - 1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

// fix heap algorithm
template<class S, class T>
inline void MaxBinaryHeap<S, T>::fixHeap(int i_Node)
{
	int max;
	int leftSon = left(i_Node);
	int rightSon = right(i_Node);

	if (leftSon >= 0 && leftSon < m_Count && m_Vector[leftSon]->GetKey() > m_Vector[i_Node]->GetKey())
	{
		max = leftSon;
	}
	else
	{
		max = i_Node;
	}

	if (rightSon >= 0 && rightSon < m_Count && m_Vector[rightSon]->GetKey() > m_Vector[max]->GetKey())
	{
		max = rightSon;
	}

	if (max != i_Node)
	{
		swap(i_Node, max);
		fixHeap(max);
	}
}

// return place of left child
template<class S, class T>
inline int MaxBinaryHeap<S, T>::left(int i_PlaceInHeap)
{
	int left = (i_PlaceInHeap * 2) + 1;

	if (left >= m_Count)
	{
		left = -1;
	}

	return left;
}

// return place of right child
template<class S, class T>
inline int MaxBinaryHeap<S, T>::right(int i_PlaceInHeap)
{
	int right = (i_PlaceInHeap * 2) + 2;

	if (right >= m_Count)
	{
		right = -1;
	}

	return right;
}

// return place of parent
template<class S, class T>
inline int MaxBinaryHeap<S, T>::parent(int i_PlaceInHeap)
{
	int parent;

	if (i_PlaceInHeap == 0)
	{
		parent = -1;
	}
	else
	{
		parent = (i_PlaceInHeap - 1) / 2;
	}

	return parent;
}

// swap two element in heap
template<class S, class T>
inline void MaxBinaryHeap<S, T>::swap(int i_First, int i_Second)
{
	int firstPlaceInHeap = m_Vector[i_First]->GetPlaceInHeap();
	int secondPlaceInHeap = m_Vector[i_Second]->GetPlaceInHeap();

	m_Vector[i_First]->SetPlaceInHeap(secondPlaceInHeap);
	m_Vector[i_Second]->SetPlaceInHeap(firstPlaceInHeap);

	HeapPair<S, T>* tempPair = m_Vector[i_Second];
	m_Vector[i_Second] = m_Vector[i_First];
	m_Vector[i_First] = tempPair;
}