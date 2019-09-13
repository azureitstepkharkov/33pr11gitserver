#include "stdafx.h"
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Stack//интерфейс
{
protected:
	Stack* Body;//внутренняя реализация - тело: или массив или список
public:
	virtual void Push(int) = 0;
	virtual int Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};
//реализация стека через массив
class StackArray : public Stack
{
public://здесь все открытые методы
	StackArray(int sizestack);
	~StackArray();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual int Pop();
	virtual void Push(int);
private://здесь все, что нужно, чтобы работать с массивом
	int* pArray;//указатель - динамический одномерный массив
	int pos;//текущий элемент
	int size;//размер массива = размеру стека
};
//
StackArray::StackArray(int sizestack)
{
	pos = 0;
	pArray = new int[sizestack];
	size = sizestack;
}
StackArray::~StackArray()
{
	delete pArray;
};
bool StackArray::isEmpty()
{
	if (pos == 0)
		return true;
	else
		return false;
}

bool StackArray::isFull()
{
	if (pos == size)
		return true;
	else
		return false;
}

int StackArray::Pop()
{
	if (!this->isEmpty())
	{
		return pArray[--pos];
	};
}

void StackArray::Push(int newitems)
{
	if (!this->isFull())
	{
		pArray[pos++] = newitems;
	};
}
//реализация через список
//Дз 1  в список из проекта DynamicListExampleEx добавить операции
//empty(),begin(),push_front()
class StackList : public Stack
{
public:
	StackList()
	{
	};
	~StackList() {};
	virtual bool isEmpty()
	{
		return List.empty();
	};
	virtual bool isFull()
	{
		return false;
	};
	virtual int Pop()
	{
		if (!List.empty())
		{

			top = List.begin();
			return *top;
		};
	};
	virtual void Push(int newelem)
	{
		List.push_front(newelem);
	};
private:
	list<int> List;
	list<int>::iterator top;
};
//
//кто принимает решение, при помощи которой структуры реализовывть стек?
//Body of stack
class StackBody :public Stack
{

public:
	StackBody(int size)
	{
		Body = new StackArray(size);
	};
	StackBody()
	{
		Body = new StackList;
	};
	virtual void Push(int items)
	{
		Body->Push(items);
	};
	virtual int Pop()
	{
		return Body->Pop();
	};
	virtual bool isEmpty()
	{
		return Body->isEmpty();
	};
	virtual bool isFull()
	{
		return Body->isFull();
	};
};
//дз № 2 заменить в StackBody список из стандартной библиотеки
//на список из проекта DynamicListExampleEx
int main()
{
	//указатель на интерфейс
	//заполняю его объектом класса Body
	Stack* s = new StackBody(10);//внутри будет создан стек через массив
	s->Push(10);
	int i = s->Pop();
	cout << i << endl;
	delete s;
	s = new StackBody();//внутри будет создан стек через список
	s->Push(10);
	i = s->Pop();
	cout << i << endl;
	delete s;
	system("pause");
    return 0;
}

