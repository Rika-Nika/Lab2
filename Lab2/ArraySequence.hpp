#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
	DynamicArray2<T> items;
	int count;
public:
	ArraySequence(const int count = 0): count(0)
	{
		int actualCount = count > 0 ? count : 1;
		//		int actualCount;
		//		if (count > 0)
		//			actualCount = count;
		//		else
		//			actualCount = 1;
		this->items = new DynamicArray2<T>(actualCount);
	}
	ArraySequence(T* items, int count);
	ArraySequence(const ArraySequence<T>& other);
public:
	virtual T GetLength() const override
	{
		return this->items.GetSize();
	}
	virtual T GetFirst() const override
	{
//		if (count < 1)
//			throw new Exception;
		if (this->items[0].HasValue())
			return this->items[0].GetValue();
		throw new Exception;
	}
	virtual T GetLast() const override;
	virtual T Get(const int i) const override;
	virtual Sequence<T>* GetSubsequence(const int start, const int end) const override;
public:
	virtual void Append(T value) override;
	virtual void Prepend(T value) override;
	virtual void InsertAt(const int index, T value) override;
	virtual void RemoveAt(const int index) override;
	virtual void Remove(T value) override; // Удаляет первое вхождение value
	virtual void RemoveAll(T value) override;
	virtual Sequence<T>* Concat(Sequence<T>* other) override;
public:
	virtual ~ArraySequence() {}
};
