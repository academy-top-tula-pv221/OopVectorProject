#pragma once
#include "IIterator.h"

template <class T>
class VectorIterator;

template <class T>
class Vector
{
	T* array;
	int size;
	int capacity;
public:
	Vector() : size{ 0 }, capacity{ 4 }, array{ new T[4] } {}
	explicit Vector(int size) : size{ size }, capacity{ size }
	{
		if (capacity < 4)
			capacity = 4;
		array = new T[capacity];
	}
	Vector(const Vector& vector) : size{ vector.size }, capacity{ vector.size }
	{
		array = new T[capacity];
		for (int i = 0; i < this->size; i++)
			array[i] = vector.array[i];
	}
	~Vector()
	{
		if (array)
			delete[] array;
	}

	Vector operator=(const Vector& vector)
	{
		if (&vector == this)
			return *this;

		if (array)
			delete[] array;
		size = vector.size;
		capacity = size;
		array = new T[capacity];
		for (int i = 0; i < this->size; i++)
			array[i] = vector.array[i];

		return *this;
	}

	int Size();
	int Capacity();

	T& operator[](int index);
	T& At(int index);

	void PushBack(T value);
	void Insert(int index, T value);

	T PopBack();
	T Replace(int index);
	//void Replace(int indexFirst, int indexLast);

	VectorIterator<T>& GetIterator()
	{
		return *(new VectorIterator<T>(this));
	}
};

template<class T>
int Vector<T>::Size()
{
	return this->size;
}

template<class T>
int Vector<T>::Capacity()
{
	return this->capacity;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return array[index];
}

template<class T>
T& Vector<T>::At(int index)
{
	return array[index];
}

template<class T>
void Vector<T>::PushBack(T value)
{
	if (size >= capacity)
	{
		capacity += capacity / 2;
		T* arrayNew = new T[capacity];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];
		delete[] array;
		array = arrayNew;
	}
	array[size++] = value;
}

template<class T>
void Vector<T>::Insert(int index, T value)
{
	if (size >= capacity)
	{
		capacity += capacity / 2;
		T* arrayNew = new T[capacity];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];
		delete[] array;
		array = arrayNew;
	}

	for (int i = size - 1; i >= index; i--)
		array[i + 1] = array[i];

	array[index] = value;
	size++;
}

template<class T>
T Vector<T>::PopBack()
{
	if (capacity - size > size / 2)
	{
		capacity = size + size / 2;
		T* arrayNew = new T[capacity];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];
		delete[] array;
		array = arrayNew;
	}

	return array[--size];
}

template<class T>
T Vector<T>::Replace(int index)
{
	if (capacity - size > size / 2)
	{
		capacity = size + size / 2;
		T* arrayNew = new T[capacity];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];
		delete[] array;
		array = arrayNew;
	}

	T result = array[index];
	for (int i = index; i < size; i++)
		array[i] = array[i + 1];
	size--;
	return result;
}

template <class T>
class VectorIterator : public IIterator<T>
{
	Vector<T>* vect;
	int index;
public:
	VectorIterator() : vect{ nullptr }, index{ 0 } {};
	VectorIterator(Vector<T>* vect) 
		: vect{ vect }, index{ 0 } {};
	VectorIterator(const VectorIterator& iter)
		: vect{ iter.vect }, index{ iter.index } {};
	VectorIterator& operator=(const VectorIterator& iter)
	{
		if (&iter == this)
			return *this;

		this->vect = iter.vect;
		this->index = iter.index;

		return *this;
	}

	void Set() override
	{
		this->index = 0;
	}
	void Next() override
	{
		this->index++;
	}
	bool IsEnd() override
	{
		return index >= vect->Size();
	}
	T& Current() override
	{
		return vect->At(index);
	}
};

