#include "stdafx.h"
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Stack//���������
{
protected:
	Stack* Body;//���������� ���������� - ����: ��� ������ ��� ������
public:
	virtual void Push(int) = 0;
	virtual int Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};
//���������� ����� ����� ������
class StackArray : public Stack
{
public://����� ��� �������� ������
	StackArray(int sizestack);
	~StackArray();
	virtual bool isEmpty();
	virtual bool isFull();
	virtual int Pop();
	virtual void Push(int);
private://����� ���, ��� �����, ����� �������� � ��������
	int* pArray;//��������� - ������������ ���������� ������
	int pos;//������� �������
	int size;//������ ������� = ������� �����
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
//���������� ����� ������
//�� 1  � ������ �� ������� DynamicListExampleEx �������� ��������
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
//��� ��������� �������, ��� ������ ������� ��������� ������������ ����?
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
//�� � 2 �������� � StackBody ������ �� ����������� ����������
//�� ������ �� ������� DynamicListExampleEx
int main()
{
	//��������� �� ���������
	//�������� ��� �������� ������ Body
	Stack* s = new StackBody(10);//������ ����� ������ ���� ����� ������
	s->Push(10);
	int i = s->Pop();
	cout << i << endl;
	delete s;
	s = new StackBody();//������ ����� ������ ���� ����� ������
	s->Push(10);
	i = s->Pop();
	cout << i << endl;
	delete s;
	system("pause");
    return 0;
}

