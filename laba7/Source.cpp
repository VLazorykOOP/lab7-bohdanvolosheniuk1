#pragma once
#include <iostream>
#include "Stack.cpp"
#include "List.h"
//#include "List.h"
using namespace std;
#pragma warning(disable : 4996)

template <typename T>
void FindMax(T* a, int s)
{
	if (a == NULL)return;
	int MaxCount = 1;
	T curMax = a[0];
	for (int i = 1; i < s; i++)
	{
		if (curMax < a[i])
		{
			curMax = a[i];
			MaxCount = 0;
		}
		if (a[i] == curMax)
			MaxCount++;
	}
	cout << "Максимальний елемент: " << curMax << endl;
	cout << "Кількість разів, коли він зустрічається в масиві: " << MaxCount << endl;
}
template <>
void FindMax(char** a, int s)
{
	if (a == NULL)return;
	int MaxCount = 1;
	char* curMax = new char[100];
	strcpy(curMax, a[0]);
	for (int i = 1; i < s; i++)
	{
		if (strcmp(curMax, a[i]) == -1)
		{
			strcpy(curMax, a[i]);
			MaxCount = 0;
		}
		if (strcmp(curMax, a[i]) == 0)
			MaxCount++;
	}
	cout << "Максимальний рядок: " << curMax << endl;
	cout << "Кількість разів, коли він зустрічається в масиві: " << MaxCount << endl;
}
template <typename T>
void SortArray(T* a, int s) // метод Шела полягає у розділі масиву на певні частини (в даному випадку ці сегиенти діляться на 2)
//та, відповідно, подальше їх сортування
{
	for (int d = s / 2; d >= 1; d /= 2)
		for (int i = d; i < s; i++)
			for (int j = i; j >= d; j -= d)
				if (a[j - d] > a[j])
					swap(a[j], a[j - d]);
}
template <>
void SortArray(char** a, int s)
{
	for (int d = s / 2; d >= 1; d /= 2)
		for (int i = d; i < s; i++)
			for (int j = i; j >= d; j -= d)
				if (strcmp(a[j - d], a[j]) == 1)
				{
					char c[100];
					strcpy(c, a[j]);
					strcpy(a[j], a[j - d]);
					strcpy(a[j - d], c);
				}
}
void Task1()
{
	int s;
	cout << "Введіть розмір вашого масиву: " << endl;
	cin >> s;
	s = max(abs(s), 1);
	double* mas = new double[s];
	cout << "Введіть елементи вашого масиву: " << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> mas[i];
	}
	cout << "Ваш масив:" << endl;
	for (int i = 0; i < s; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	FindMax(mas, s);
	cout << endl;
	cout << "Введіть розмір масиву рядків:" << endl;
	cin >> s;
	char** str = new char* [30];
	cin.get();
	cout << "Введіть рядки цього масиву:" << endl;
	for (int i = 0; i < s; i++)
	{
		str[i] = new char[30];
		cin.getline(str[i], 30);
	}
	FindMax(str, s);
	cout << "Відсортований масив : " << endl;
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
}
void Task2()
{
	int s;
	cout << "Введіть розмір вашого масиву: " << endl;
	cin >> s;
	s = max(abs(s), 1);
	double* mas = new double[s];
	cout << "Введіть елементи вашого масиву: " << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> mas[i];
	}
	cout << "Ваш масив: " << endl;
	for (int i = 0; i < s; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	SortArray(mas, s);
	cout << "Відсортований масив: " << endl;
	for (int i = 0; i < s; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	cout << "Введіть рзмір масиву рядків:" << endl;
	cin >> s;
	char** str = new char* [30];
	cin.get();
	cout << "Введіть рядки цього масиву:" << endl;
	for (int i = 0; i < s; i++)
	{
		str[i] = new char[30];
		cin.getline(str[i], 30);
	}
	SortArray(str, s);
	cout << "Відсортований масив рядків:" << endl;
	for (int i = 0; i < s; i++)
	{
		cout << str[i] << " ";
	}
}
void Task3()
{
	Stack<double> st = Stack<double>();
	cout << "Введіть розмір стеку" << endl;
	int s;
	cin >> s;
	double d;
	cout << "Введіть " << s << " елементів стеку" << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> d;
		st.add(d);
	}
	cout << endl << "Ваш стек: " << endl;
	for (int i = 0; i < st.getSize(); i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
	cout << endl << "Робота метода рор: " << endl;
	st.pop();
	for (int i = 0; i < st.getSize(); i++)
	{
		cout << st[i] << " ";
	}
	cout << endl << endl;
}
void Task4()
{
	List<double> l = List<double>();
	cout << "Введіть кількість елементів вашого списку" << endl;
	int s;
	double d;
	cin >> s;
	cout << "Введіть " << s << " елементів списку" << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> d;
		l.push(d);
	}
	cout << endl << "Ваш список: " << endl;
	for (int i = 0; i < l.length(); i++)
	{
		cout << l[i] << " ";
	}
	cout << endl << endl;
	cout << "Метод рор (додатково повертає елемент, що видаляє):" << endl;
	cout << l.pop() << endl;
	cout << "Виведення ітератором:" << endl << endl;
	for (List<double>::Iterator i = l.begin(); i != nullptr; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "ukr");
	int f = 1;
	while (f >= 1 && f <= 4)
	{
		system("cls");
		cout << "Оберіть дію: " << endl;
		cout << "1 - Знайти максимальне значення в масиві та кількість разів, коли воно зустрічається" << endl;
		cout << "2 - Відсортувати масив: " << endl;
		cout << "3 - Приклад класу стек: " << endl;
		cout << "4 - Приклад класу список: " << endl;
		cout << " - Вихід" << endl;
		cin >> f;
		switch (f)
		{
		case 1:Task1(); break;
		case 2:Task2(); break;
		case 3:Task3(); break;
		case 4:Task4(); break;
		default:
			break;
		}
		system("pause");
	}
	return 0;
}