#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct ListElement
{
public:
	ListElement* next = nullptr;
	T value;
};
template<typename T>
class List
{
	ListElement<T>* head;
public:
	List()
	{
		head = nullptr;
	}
	List(T t)
	{
		push(t);
	}
	class Iterator
	{
		ListElement<T>* ptr;
	public:
		Iterator(ListElement<T>* p)
		{
			ptr = p;
		}
		Iterator operator++(int i)
		{
			ptr = ptr->next;
			return *this;
		}
		Iterator operator--(int i)
		{
			if (ptr == begin())
			{
				ptr = nullptr;
				return *this;
			}
			ListElement<T>* temp = begin();
			while (temp->next != ptr)
			{
				temp = temp->next;
			}
			return *this;
		}
		bool operator!=(const Iterator& i1)
		{
			return i1.ptr != this->ptr;
		}
		bool operator==(const Iterator& i1)
		{
			return i1.ptr == this->ptr;
		}
		Iterator& operator=(const Iterator& i)
		{
			return this->ptr = i.ptr;
			return *this;
		}
		ListElement<T>* operator->()
		{
			return ptr;
		}
		T& operator*()
		{
			return ptr->value;
		}
		ListElement<T>* operator()()
		{
			return ptr;
		}
	};

	Iterator begin()
	{
		return  Iterator(head);
	}
	Iterator end()
	{
		if (head == nullptr)
			return nullptr;
		ListElement<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		return  Iterator(temp);
	}
	void push(T value)
	{
		if (head == nullptr)
		{
			head = new ListElement<T>();
			head->value = value;
			return;
		}
		ListElement<T>* el = new ListElement<T>();
		el->value = value;
		ListElement<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = el;
	}
	T pop()
	{
		if (head == nullptr)return NULL;
		ListElement<T>* temp = end()();
		T t = temp->value;
		temp = begin()();
		while (temp->next != end()())
			temp = temp->next;
		temp->next = nullptr;
		return t;
	}
	int length()
	{
		if (head == nullptr)return 0;
		ListElement<T>* temp = head;
		int i = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			i++;
		}
		return i;
	}
	T& operator[](int in)
	{
		if (in<0 || in>length())throw exception("Out of range");
		ListElement<T>* temp = head;
		int i = 0;
		while (temp->next != nullptr && i != in)
		{
			temp = temp->next;
			i++;
		}
		return temp->value;
	}
	void show()
	{
		if (head == nullptr)
			return;
		ListElement<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
};