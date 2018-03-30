#pragma once
template <class T, size_t N>
class FixedList
{
public:
	FixedList();
	~FixedList();
	const T& get(unsigned int index) const;
	T& operator[](unsigned int index);
	int getFirstIndex(const T& t) const;
	size_t size() const;
	size_t capacity() const;
	bool add(const T& t);
	T remove(const T& t);
private:
	T contents [N];
	size_t cSize;
	size_t cCapacity;
};

template<class T, size_t N>
inline FixedList<T, N>::FixedList()
{
	cSize = 0;
	cCapacity = N;
}

template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const
{
	if (index < cSize)
	{
		return contents[index];
	}
	else {
		throw std::range_error("Out of range.");
	}
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index)
{
	if (index < cSize)
	{
		return contents[index];
	}
	else {
		throw std::range_error("Out of range.");
	}
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{
	if (cSize > 0) {
		for (int i = 0; i < cSize; i++)
		{
			if (contents[i] == t) 
			{
				return i;
			}
		}
	}
	return -1;	
}


template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return cSize;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return cCapacity;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	if (cSize < cCapacity)
	{
		contents[cSize++] = t;
		return true;
	}
	return false;
}

template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{
	int index = getFirstIndex(t);

	if (index >= 0) {
		for (int i = index; i < cSize; i++) {
			contents[i] = contents[i + 1];
		}
		--cSize;
		return t;
	}
	return NULL;
}






