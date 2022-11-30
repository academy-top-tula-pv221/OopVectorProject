#include "Vector.h"
template<class T>
inline int Vector<T>::Size()
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

