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

// Constructor
// Initialize size to 0 and capacity to N
template<class T, size_t N>
inline FixedList<T, N>::FixedList()
{
	cSize = 0;
	cCapacity = N;
}

// Empty Destructor
template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
}

// Get
// Param: index
// PRE: index must be in range
// POST: the value from the index
// Return: the value from the index
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

// []
// Param: index
// PRE: index must be in range
// POST: the value from the index
// Return: the value from the index
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


// Gets the first index of the first occurence
// Param: the value
// PRE: the index will be in range
// POST: the index of the first occurence
// Return: the index of the first occurence otherwise return -1 if not found
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

// Size
// Returns the current size of the FixedList
template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return cSize;
}

// Capacity
// Returns the capacity of the FixedList
template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return cCapacity;
}

// Add
// Param: the value
// PRE: Must be the same type of the FixedList
// POST: The value will be added if the size is less than or equal to the capacity
// Return: true if the value has been added or false if it has not
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

// Remove
// Param: the value
// PRE: The FixedList must not be empty
// POST: the value will be removed 
// Return: the value if it has been removed and null if it has not been removed
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






