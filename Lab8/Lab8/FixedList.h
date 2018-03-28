#pragma once
template <class T, size_t N>
class FixedList
{
public:
	const T& get(unsigned int index) const;
	T& operator[](unsigned int index);
	int getFirstIndex(const T& t) const;
	size_t size() const;
	bool add(const T& t);
	T remove(const T& t);
private:
	T a [N];
};

