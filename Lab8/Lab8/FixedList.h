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
	bool add(const T& t);
	//T remove(const T& t);
private:
	T contents [N];
	size_t size;
	size_t capacity = N;
};

template<class T, size_t N>
inline FixedList<T, N>::FixedList()
{
	size = 0;
}

template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const
{
	if (index < size)
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
	if (index < size)
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
	if (size > 0) {
		return t[0];
	}
	return -1;
	
}

