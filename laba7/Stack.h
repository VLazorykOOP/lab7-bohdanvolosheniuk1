#pragma once
#include<vcruntime.h>
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
	T* array;
	int size = 0;
	int maxSize;
public:
	Stack()
	{
		array = new T[10];
		maxSize = 10;
	}
	Stack(int n)
	{
		array = new T[n];
		maxSize = n;
	}
	Stack(int s, T* D, T* I)
	{
		array = new T[s];
		maxSize = s;
		size = s;
		for (int i = 0; i < s; i++)
		{
			array[i] = I[i];
		}
	}
	~Stack()
	{
		if (array)
			delete[]array;
		size = 0;
	}
	int getSize()
	{
		return size;
	}
	void add(T value)
	{
		if (size == maxSize)
		{
			cout << "Stack is already full";
			return;
		}
		array[size] = value;
		size++;
	}
	void pop()
	{
		if (size > 0)
			size--;
	}
	T& operator[](int);
};

