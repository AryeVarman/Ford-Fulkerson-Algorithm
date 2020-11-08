#ifndef __List_H
#define __List_H

#include"ListNode.h"

// class T should have
// operator==
// operator>=
// operator<=
// operator>
// operator<

template<class T>
class List
{
private:
	ListNode<T>* m_Head;
	ListNode<T>* m_Tail;
	int m_Count;

public:
	List();
	List(const List<T>& i_List);
	~List();

	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	int GetCount();

	bool PushFront(T i_Node);
	bool PushBack(T i_Node);
	bool DeleteHead();
	bool DeleteTail();
	bool IsEmpty();
	ListNode<T>* IsInList(T i_NodeToFind);
	void Clear();
};
#endif // !__List_H



//implements//
//============


template<class T>
List<T>::List()
{
	m_Head = nullptr;
	m_Tail = nullptr;
	m_Count = 0;
}

template<class T>
List<T>::List(const List<T>& i_List)
{
	m_Head = i_List.m_Head;
	m_Tail = i_List.m_Tail;
	m_Count = i_List.m_Count;
}

template<class T>
List<T>::~List()
{
	Clear();
}

template<class T>
inline ListNode<T>* List<T>::GetHead()
{
	return m_Head;
}

template<class T>
inline ListNode<T>* List<T>::GetTail()
{
	return m_Tail;
}

template<class T>
inline int List<T>::GetCount()
{
	return m_Count;
}

// enter new item to head of List
template<class T>
bool List<T>::PushFront(T i_Data)
{
	bool isValid = false;

	ListNode<T>* newNode = new ListNode<T>(i_Data);

	if (newNode != nullptr)
	{
		newNode->SetNext(this->m_Head);
		m_Head = newNode;
		m_Count++;
		isValid = true;
	}

	if (m_Tail == nullptr && isValid == true)
	{
		m_Tail = newNode;
	}

	return isValid;
}

// enter new item to tail of List
template<class T>
bool List<T>::PushBack(T i_Data)
{
	bool isValid = false;

	ListNode<T>* newNode = new ListNode<T>(i_Data);

	if (newNode != nullptr)
	{
		if (m_Count == 0)
		{
			m_Head = newNode;
			m_Tail = newNode;
		}
		else
		{
			m_Tail->SetNext(newNode);
			m_Tail = m_Tail->GetNext();
		}
		m_Count++;
		isValid = true;
	}

	return isValid;
}

// delete head of list and return true if successfull
template<class T>
bool List<T>::DeleteHead()
{
	bool isValid = true;

	if (m_Count == 0)
	{
		isValid = false;
	}
	else if (m_Count == 1)
	{
		delete m_Head;
		m_Head = m_Tail = nullptr;
		m_Count--;
	}
	else
	{
		ListNode<T>* tempNode = m_Head;
		m_Head = m_Head->GetNext();
		delete tempNode;
		m_Count--;
	}

	return isValid;
}

// delete tail of list and return true if successfull
template<class T>
bool List<T>::DeleteTail()
{
	bool isValid = true;

	if (m_Count == 0)
	{
		isValid = false;
	}
	else if (m_Count == 1)
	{
		delete m_Tail;
		m_Head = m_Tail = nullptr;
		m_Count--;
	}
	else
	{
		T* tempNode = m_Head;
		while (tempNode->GetNext() != m_Tail)
		{
			tempNode = tempNode->GetNext();
		}

		delete m_Tail;
		m_Tail = tempNode;
		m_Count--;
	}

	return isValid;
}

template<class T>
inline bool List<T>::IsEmpty()
{
	return m_Count == 0;
}

// check if item is in list and return it's listNode
template<class T>
ListNode<T>* List<T>::IsInList(T i_DataToFind)
{
	bool found = false;
	ListNode<T>* tempNode = m_Head;

	while (found == false && tempNode != nullptr)
	{
		if (tempNode->GetData() == i_DataToFind)
		{
			found = true;
		}
		tempNode = tempNode->GetNext();
	}

	return tempNode;
}

// delete all listNodes
template<class T>
void List<T>::Clear()
{
	while (m_Head != nullptr)
	{
		DeleteHead();
	}
}