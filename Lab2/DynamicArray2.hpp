#pragma once
#include "Optional.hpp"


template <class T>
class DynamicArray2
{
private:
	Optional<T>* items;
	int size;
public:
	DynamicArray2(T* items);
	DynamicArray2(const int size)
	{
		if (size < 1)
			throw new Exception;
		this->items = new T[size];
		for (int i = 0; i < size; i++)
			this->items[i] = Optional<T>::Empty();
		this->size = size;
	}
	DynamicArray2(const DynamicArray2<T> &array);
public:
	int GetSize() const { return this->size; }
	T Get(const int index) const
	{
		if (index < 0 || index >= this->size || !this->items->HasValue())
			throw new Exception;
		return this->items[index]->GetValue();
	}
public:
	void Set(const int index, const T value)
	{
		if (index < 0 || index >= this->size)
			throw new Exception;
		this->items[index] = new Optional<T>(value);
	}
	void Resize(int newSize);

};


///////////////////////////////////////
void f()
{
	Optional<int>* o1 = new Optional<int>(1);
	Optional<int>* o2 = new Optional<int>(2);
	Optional<int>* o3 = new Optional<int>(1);
	if (o1 == o2){}
	if (o1 == o3){}

	Optional<int> oo1(1);
	Optional<int> oo2(2);
	Optional<int> oo3(1);
	Optional<int> oo4 = Optional<int>::Empty();
	if (oo1 == oo2) {}
	if (oo1 == oo3) {}
	if (oo4 == oo4) {}
}