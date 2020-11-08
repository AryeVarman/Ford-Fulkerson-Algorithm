#ifndef __ListNode_H
#define __ListNode_H


// class T should have
// operator==
// operator>=
// operator<=
// operator>
// operator<

template<class T>
class ListNode
{
private:
	T m_Data;
	ListNode<T>* m_Next;

public:
	ListNode<T>(T i_Data, ListNode<T>* i_Next = nullptr);

	T& GetData();
	ListNode<T>* GetNext();

	void SetNext(ListNode<T>* i_Next);
	void SetData(T i_Data);

	bool operator==(const ListNode<T>& i_ListNodeToCompare);
	bool operator>=(const ListNode<T>& i_ListNodeToCompare);
	bool operator<=(const ListNode<T>& i_ListNodeToCompare);
	bool operator>(const ListNode<T>& i_ListNodeToCompare);
	bool operator<(const ListNode<T>& i_ListNodeToCompare);
};


#endif // !__ListNode_H

template<class T>
inline ListNode<T>::ListNode(T i_Data, ListNode<T>* i_Next)
{
	m_Data = i_Data;
	m_Next = i_Next;
}

template<class T>
inline T& ListNode<T>::GetData()
{
	return m_Data;
}

template<class T>
inline ListNode<T>* ListNode<T>::GetNext()
{
	return m_Next;
}

template<class T>
inline void ListNode<T>::SetNext(ListNode<T>* i_Next)
{
	m_Next = i_Next;
}

template<class T>
inline void ListNode<T>::SetData(T i_Data)
{
	m_Data = i_Data;
}

template<class T>
inline bool ListNode<T>::operator==(const ListNode<T>& i_ListNodeToCompare)
{
	return m_Data == i_ListNodeToCompare.m_Data;
}

template<class T>
inline bool ListNode<T>::operator>=(const ListNode<T>& i_ListNodeToCompare)
{
	return m_Data >= i_ListNodeToCompare.m_Data;
}

template<class T>
inline bool ListNode<T>::operator<=(const ListNode<T>& i_ListNodeToCompare)
{
	return m_Data <= i_ListNodeToCompare.m_Data;
}

template<class T>
inline bool ListNode<T>::operator>(const ListNode<T>& i_ListNodeToCompare)
{
	return m_Data > i_ListNodeToCompare.m_Data;
}

template<class T>
inline bool ListNode<T>::operator<(const ListNode<T>& i_ListNodeToCompare)
{
	return m_Data < i_ListNodeToCompare.m_Data;
}