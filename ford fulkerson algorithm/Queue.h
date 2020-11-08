#ifndef __Queue_H
#define __Queue_H

#include"List.h"

template<class T>
class Queue
{
private:
	List<T> m_List;
	int m_Count;

public:
	Queue();
	Queue(List<T> i_List);

	bool IsEmpty();
	void Enqueue(T i_Obj);
	T& Dequeue();
	void Clear();
};

#endif // !__Queue_H

template<class T>
inline Queue<T>::Queue()
{
	m_Count = 0;
}

template<class T>
inline Queue<T>::Queue(List<T> i_List) :m_List(i_List)
{
	m_Count = i_List.m_Count;
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	return m_Count == 0;
}

template<class T>
inline void Queue<T>::Enqueue(T i_Obj)
{
	m_List.PushBack(i_Obj);
	m_Count++;
}

template<class T>
inline T& Queue<T>::Dequeue()
{
	if (m_Count > 0)
	{
		ListNode<T> listNode = *(m_List.GetHead());
		m_List.DeleteHead();
		m_Count--;
		return listNode.GetData();
	}

	throw m_Count;
}

template<class T>
inline void Queue<T>::Clear()
{
	m_Count = 0;
	m_List.Clear();
}