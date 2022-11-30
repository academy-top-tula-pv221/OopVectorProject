#pragma once
#include "IIterator.h"

template <class T>
class ListIterator;

template <class T>
struct Node
{
	T value;
	Node<T>* next;
};

template <class T>
class List
{
	Node<T>* head;
	int size;
public:
	List() : head{ nullptr }, size{ 0 } {}
	~List()
	{
		Node<T>* del = head;
		while (del)
		{
			head = head->next;
			delete del;
			del = head;
		}
	}
	void Add(T value)
	{
		Node<T>* node = new Node<T>;
		node->value = value;
		node->next = head;
		head = node;
		size++;
	}

	int Size()
	{
		return this->size;
	}

	T At(int index)
	{
		Node<T>* curr = head;
		for (int i = 0; i < index; i++)
			curr = curr->next;
		return curr->value;
	}

	Node<T>* Head()
	{
		return head;
	}

	ListIterator<T>& GetIterator()
	{
		return *(new ListIterator<T>(this));
	}
};

template <class T>
class ListIterator : public IIterator<T>
{
	List<T>* list;
	Node<T>* node;
public:
	ListIterator() : list{ nullptr }, node{ nullptr } {}
	
	ListIterator(List<T>* list)
		: list{ list }, node{ list->Head() } {};

	ListIterator(const ListIterator& iter)
		: list{ iter.list }, node{ iter.node } {}

	ListIterator& operator=(const ListIterator& iter)
	{
		this->list = iter.list;
		this->node = iter.node;

		return *this;
	}

	void Set() override
	{
		node = list->Head();
	}
	void Next() override
	{
		node = node->next;
	}
	bool IsEnd() override
	{
		return !node;
	}
	T& Current() override
	{
		return node->value;
	}
};
