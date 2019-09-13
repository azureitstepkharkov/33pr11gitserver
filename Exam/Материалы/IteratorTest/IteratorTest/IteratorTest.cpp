#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual int current()=0;
	virtual int begin() = 0;
	virtual int end() = 0;
};
template<class T>
struct myinterator
{
	virtual bool hasNext() = 0;
	virtual T current() = 0;
	virtual T begin() = 0;
	virtual T end() = 0;
};
class MyCollection : public Iterator
{
private:
	const static int N = 10;
	int arr[N];
	int currIndex;
public:
	virtual bool hasNext() 
	{
		if (currIndex >= 0 && currIndex <= N - 1)
			return true;
		if (currIndex < 0 || currIndex > N - 1)
			return false;
	};
	virtual int current() 
	{ 
		int curvalue = arr[currIndex]; 
		currIndex++;
		return currIndex;//нужен метод обнуления reset
	};
	//[i++]
	virtual int begin() { return arr[0]; };
	virtual int end() { return arr[N - 1]; };
	MyCollection()
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand()%(10 - 1 + 1) + 1;
		}
		currIndex = 0;
	}
};

class Collection : public myinterator<int>
{
private:
	const static int N = 10;
	int arr[N];
	int currIndex;
public:
	virtual bool hasNext()
	{
		if (currIndex >= 0 && currIndex <= N - 1)
			return true;
		if (currIndex < 0 || currIndex > N - 1)
			return false;
	};
	virtual int current()
	{
		int curvalue = arr[currIndex];
		currIndex++;
		return currIndex;//нужен метод обнуления reset
	};
	//[i++]
	virtual int begin() { return arr[0]; };
	virtual int end() { return arr[N - 1]; };
	Collection()
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % (10 - 1 + 1) + 1;
		}
		currIndex = 0;
	}
};
int calcFactorial(int N)
{
	static int A = 0;
	A++;
	cout << "A = " << A << endl;
	if (N == 0)
		return 1;
	else
		return calcFactorial(N - 1);
}
int main()
{
	int R = calcFactorial(5);
	//java style code
	MyCollection col;
	while (col.hasNext())
	{
		cout << col.current() << endl;
		//int x = col.current();
	};

	system("pause");
    return 0;
}

