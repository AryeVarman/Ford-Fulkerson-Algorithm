#ifndef __Vector_H
#define __Vector_H

template<class U>
class Vector
{
private:
	U* m_Arr;
	int m_Count;
	int m_Capacity;

public:
	Vector();
	Vector(int i_size);
	Vector(U* m_Arr, int i_ArrSize);
	Vector(const Vector<U>& i_VectorToCopy);
	~Vector();

	int GetCount() const;
	int GetCapacity();
	U* GetArr();

	bool Reserve(int i_numberOfItems);
	bool PushBack(const U& i_Obj);
	U& PopBack();
	bool Empty();

	bool CopyVector(Vector<U> i_VectorToCopy);

	U& operator[](int i_PlaceInArr);
	void operator=(U* i_poinetToArr);


	bool CopyArr(U* i_ArrToCopy, int i_SizeOfArrToCopy);
	static bool CopyArr(U* i_Source, int i_SourceSize, U* i_Destination, int i_DestinationCapacity);
};


#endif // !__Vector_H

template<class U>
inline Vector<U>::Vector()
{
	m_Capacity = 1;
	m_Count = 0;
	m_Arr = new U[m_Capacity];
}

template<class U>
inline Vector<U>::Vector(int i_size)
{
	m_Capacity = i_size;
	m_Count = 0;
	m_Arr = new U[m_Capacity];
}

template<class U>
inline Vector<U>::Vector(U* i_Arr, int i_ArrSize)
{
	m_Capacity = i_ArrSize;
	m_Count = i_ArrSize;
	m_Arr = new U[m_Capacity];
	CopyArr(i_Arr, i_ArrSize);
}

template<class U>
inline Vector<U>::Vector(const Vector<U>& i_VectorToCopy)
{
	m_Capacity = i_VectorToCopy.m_Capacity;
	m_Count = i_VectorToCopy.m_Count;
	m_Arr = new U[i_VectorToCopy.m_Capacity];
	CopyArr(i_VectorToCopy.m_Arr, i_VectorToCopy.m_Count);
}

template<class U>
inline Vector<U>::~Vector()
{
	delete[] m_Arr;
}

template<class U>
inline int Vector<U>::GetCount() const
{
	return m_Count;
}

template<class U>
inline int Vector<U>::GetCapacity()
{
	return m_Capacity;
}

template<class U>
inline U* Vector<U>::GetArr()
{
	return m_Arr;
}

// reserve place for vector array
template<class U>
inline bool Vector<U>::Reserve(int i_numberOfItems)
{
	bool succeed = false;

	if (i_numberOfItems > m_Capacity)
	{
		try
		{
			U* tempArr = new U[i_numberOfItems];
			CopyArr(m_Arr, m_Count, tempArr, i_numberOfItems);
			delete[] m_Arr;
			m_Arr = tempArr;
			m_Capacity = i_numberOfItems;
			succeed = true;
		}
		catch (void* m_Arr)
		{
		}
	}

	return succeed;
}

// add new item at end of array
template<class U>
inline bool Vector<U>::PushBack(const U& i_Obj)
{
	bool suceed = false;
	try
	{
		if (m_Count == m_Capacity)
		{
			Reserve(m_Capacity * 2);
		}
		m_Arr[m_Count] = U(i_Obj);
		m_Count++;
		suceed = true;
	}
	catch (int m_Count)
	{
	}

	return suceed;
}

// delete item at end of array and return it
template<class U>
inline U& Vector<U>::PopBack()
{
	if (m_Count > 0)
	{
		m_Count--;

	}
	else
	{
		throw m_Count;
	}

	return m_Arr[m_Count];
}

template<class U>
inline bool Vector<U>::Empty()
{
	return m_Count == 0;
}

template<class U>
inline bool Vector<U>::CopyVector(Vector<U> i_VectorToCopy)
{
	m_Capacity = i_VectorToCopy.m_Capacity;
	m_Count = i_VectorToCopy.m_Count;

	delete[] m_Arr;
	m_Arr = new U[m_Capacity];
	CopyArr(i_VectorToCopy.m_Arr, i_VectorToCopy.m_Count, m_Arr, m_Capacity);
}

template<class U>
inline void Vector<U>::operator=(U* i_poinetToArr)
{
	m_Arr = i_poinetToArr;
}

template<class U>
inline bool Vector<U>::CopyArr(U* i_Source, int i_SourceSize, U* i_Destination, int i_DestinationCapacity)
{
	bool succeed = false;

	if (i_DestinationCapacity >= i_SourceSize)
	{
		for (int i = 0; i < i_SourceSize; i++)
		{
			i_Destination[i] = i_Source[i];
		}
		succeed = true;
	}

	return succeed;
}

template<class U>
inline bool Vector<U>::CopyArr(U* i_ArrToCopy, int i_SizeOfArrToCopy)
{
	return CopyArr(i_ArrToCopy, i_SizeOfArrToCopy, m_Arr, m_Capacity);
}

template<class U>
U& Vector<U>::operator[](int i_PlaceInArr)
{
	return m_Arr[i_PlaceInArr];
}