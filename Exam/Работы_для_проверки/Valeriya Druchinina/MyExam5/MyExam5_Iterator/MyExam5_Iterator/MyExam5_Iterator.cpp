#include "pch.h"
#include <iostream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;


class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual int current() = 0;
	virtual int begin() = 0;
	virtual int end() = 0;

};


class MyClassList : public Iterator
{
private:
	const static int N = 15;
	int arr[N];
	int currIndex;

public:

	// hasNext()
	virtual bool hasNext()
	{
		if (currIndex >= 0 && currIndex <= N - 1)
			return true;
		if (currIndex < 0 || currIndex > N - 1)
			return false;
	}

	// current()
	virtual int current()
	{
		int curvalue = arr[currIndex];
		currIndex++;
		return currIndex;
	}
	// begin()
	virtual int begin()
	{ 
		return arr[0]; 
	}
	//end() 
	virtual int end() 
	{ 
		return arr[N - 1]; 
	}


	MyClassList()
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand() % (15 - 1 + 1) + 1;
		}
		currIndex = 0;
	}

	friend ostream& operator << (ostream& os,
		const MyClassList& t)
	{
		os << "currIndex = " << t.currIndex << endl;
		return os;
	}

};



int main()
{
	std::cout << "MyClassList!\n";
	MyClassList List;

	while (List.hasNext())
	{
		cout << List.current() << endl;
		
	};

	system("pause");
	return 0;


    
}

