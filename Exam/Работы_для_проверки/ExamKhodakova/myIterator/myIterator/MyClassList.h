#pragma once
#include"pch.h"
#include"Iterator.h"


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
