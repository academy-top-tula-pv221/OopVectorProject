#pragma once
class Vector
{
	int* array;
	int size;
	int capacity;
public:
	Vector() : array{ nullptr }, size{ 0 } {}
	Vector(int size) : size{ size }
	{
		array = new int[this->size];
	}
	Vector(const Vector& vector) : size{ vector.size }
	{
		array = new int[this->size];
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
		array = new int[size];
		for (int i = 0; i < this->size; i++)
			array[i] = vector.array[i];

		return *this;
	}

	int Size();
	int Capacity();

	int& operator[](int index);
	int& At(int index);

	void PushBack(int value);
	void Insert(int index, int value);

	int PopBack();
	int Replace(int index);
	void Replace(int indexFirst, int indexLast);
};

