#ifndef __HeapPair_H
#define __HeapPair_H

// class S hould have	||   	Class T should have
// operator==			||   	operator=
// operator>=			||   
// operator<=			||   
// operator>			||   
// operator<			||   
// operator=			||   


template <class S, class T>
class HeapPair
{
private:
	S m_Key;
	T m_Data;
	int m_PlaceInHeap;

public:
	HeapPair();
	HeapPair(S i_Key, T i_Data, int i_PlaceInHeap);
	//HeapPair(const HeapPair& i_Pair);

	S& GetKey();
	T& GetData();
	int GetPlaceInHeap();

	void SetKey(const S& i_Key);
	void SetData(const T& i_Data);
	bool SetPlaceInHeap(int i_PlaceInHeap);

	bool operator==(const HeapPair& i_PairToCompare);
	bool operator>=(const HeapPair& i_PairToCompare);
	bool operator<=(const HeapPair& i_PairToCompare);
	bool operator>(const HeapPair& i_PairToCompare);
	bool operator<(const HeapPair& i_PairToCompare);
	void operator=(const HeapPair& i_PairToCompare);

};
#endif // !__Pair_H

template<class S, class T>
inline HeapPair<S, T>::HeapPair()
{ }

template<class S, class T>
inline HeapPair<S, T>::HeapPair(S i_Key, T i_Data, int i_PlaceInHeap)
{
	m_Key = i_Key;
	m_Data = i_Data;
	m_PlaceInHeap = i_PlaceInHeap;
}

template<class S, class T>
inline S& HeapPair<S, T>::GetKey()
{
	return m_Key;
}

template<class S, class T>
inline T& HeapPair<S, T>::GetData()
{
	return m_Data;
}

// return the place in heap
template<class S, class T>
inline int HeapPair<S, T>::GetPlaceInHeap()
{
	return m_PlaceInHeap;
}

template<class S, class T>
inline void HeapPair<S, T>::SetKey(const S& i_Key)
{
	m_Key = i_Key;
}

template<class S, class T>
inline void HeapPair<S, T>::SetData(const T& i_Data)
{
	m_Data = i_Data;
}

// set the place in heap
template<class S, class T>
inline bool HeapPair<S, T>::SetPlaceInHeap(int i_PlaceInHeap)
{
	bool succeed = false;
	if (i_PlaceInHeap >= 0)
	{
		succeed = true;
		m_PlaceInHeap = i_PlaceInHeap;
	}
	return succeed;
}

template<class S, class T>
inline bool HeapPair<S, T>::operator==(const HeapPair& i_PairToCompare)
{
	return m_Key == i_PairToCompare.m_Key;
}

template<class S, class T>
inline bool HeapPair<S, T>::operator>=(const HeapPair& i_PairToCompare)
{
	return m_Key >= i_PairToCompare.m_Key;
}

template<class S, class T>
inline bool HeapPair<S, T>::operator<=(const HeapPair& i_PairToCompare)
{
	return m_Key <= i_PairToCompare.m_Key;
}

template<class S, class T>
inline bool HeapPair<S, T>::operator>(const HeapPair& i_PairToCompare)
{
	return m_Key > i_PairToCompare.m_Key;

}

template<class S, class T>
inline bool HeapPair<S, T>::operator<(const HeapPair& i_PairToCompare)
{
	return m_Key < i_PairToCompare.m_Key;
}

template<class S, class T>
inline void HeapPair<S, T>::operator=(const HeapPair& i_PairToCompare)
{
	m_Key = i_PairToCompare.m_Key;
	m_Data = i_PairToCompare.m_Data;
}