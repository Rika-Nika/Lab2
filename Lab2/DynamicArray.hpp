#pragma once

class Exception{};

template <class T>
class DynamicArray2
{
private:
	T* items;
	bool* itemsCheck;
	int size;
public:
	DynamicArray2(T* items);
	DynamicArray2(const int size)
	{
		if ( size < 0 )
			throw new Exception;		
		this->items = new T[size];
		this->itemsCheck = new bool[size];
		for (int i = 0; i < size; i++)
			this->itemsCheck[i] = false;
		this->size = size;
	}
	DynamicArray2(const DynamicArray2<T> &array);
public:
	int GetSize() const { return this->size; }
	T Get(const int index) const
	{
		if (index < 0 || index >= this->size || !this->itemsCheck[index])
			throw new Exception;
		return this->items[index];
	}
public:
	void Set(const int index, const T value)
	{
		if (index < 0 || index >= this->size)
			throw new Exception;
		this->items[index] = value;
		this->itemsCheck[index] = true;
	}
	void Resize(int newSize);
};
