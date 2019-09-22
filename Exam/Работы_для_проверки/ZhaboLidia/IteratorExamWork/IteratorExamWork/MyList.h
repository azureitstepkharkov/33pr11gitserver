#pragma once
#include"ListItem.h"
class MyList
{
private:
	ListItem* pBeg;
	ListItem* pEnd;
	void deleteList()
	{
		ListItem* pCurrent = pBeg;
		while (pCurrent != NULL)
		{
			ListItem* pTmp = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pTmp;
		}
		pBeg = NULL;
		pEnd = NULL;
	}
public:
	MyList()
	{
		pBeg = NULL;
		pEnd = NULL;
	}
	~MyList()
	{
		if (pBeg != NULL && pEnd != NULL)
			deleteList();
	}
	void print()
	{
		int counter = 0;
		ListItem* pCurrent = pBeg;
		while (pCurrent != NULL)
		{
			counter++;
			cout << "item #" << counter << ": ";
			cout << pCurrent->info.name << " " << pCurrent->info.age << endl;

			pCurrent = pCurrent->pNext;
		}
	}
	void printFromEndToBeg()
	{
		ListItem* pCurrent = pEnd;
		while (pCurrent != NULL)
		{
			cout << pCurrent->info.name << " " << pCurrent->info.age << endl;
			pCurrent = pCurrent->pPrev;
		}
	}
	ListInfo getItem(int num)
	{
		int counter = 0;
		ListItem* pCurrent = pBeg;
		while (pCurrent != NULL)
		{
			if (num == counter)
			{
				return pCurrent->info;
			}
			counter++;
			pCurrent = pCurrent->pNext;
		}
		//Должна быть !
		//исключительная ситуация - вышли за границы: 
		//в списке элементов меньше
		ListInfo info;
		info.name = "NoName";
		info.age = 0;
		return info;
	}
	void AddEnd(ListInfo& newInfo)
	{
		if (pEnd != NULL)
		{
			ListItem* pNew = new ListItem();
			pNew->info.name = newInfo.name;
			pNew->info.age = newInfo.age;
			pNew->pNext = NULL;
			pNew->pPrev = pEnd;

			pEnd->pNext = pNew;
			pEnd = pNew;
		}
		else
		{
			pBeg = new ListItem();
			pBeg->info.name = newInfo.name;
			pBeg->info.age = newInfo.age;
			pBeg->pNext = NULL;
			pBeg->pPrev = NULL;
			pEnd = pBeg;
		}
	}
	void AddAfterFirst(ListInfo& newInfo)
	{
		if (pBeg != NULL)
		{
			ListItem* pNew = new ListItem;
			pNew->info.name = newInfo.name;
			pNew->info.age = newInfo.age;
			pNew->pNext = NULL;
			pNew->pPrev = NULL;

			pNew->pNext = pBeg->pNext;
			pBeg->pNext->pPrev = pNew;
			pBeg->pNext = pNew;
			pNew->pPrev = pBeg;

		}
		else
		{
			//программный код из AddEnd(ListInfo& newInfo)
		}
	}
	void AddAfterItem(int num, ListInfo& newInfo)
	{
		int counter = 0;
		ListItem* pCurrent = pBeg;
		while (pCurrent != NULL)
		{
			if (num == counter)
			{
				//вставка после найденного
				ListItem* pNew = new ListItem();
				pNew->info.name = newInfo.name;
				pNew->info.age = newInfo.age;
				pNew->pPrev = pCurrent;
				pNew->pNext = pCurrent->pNext;
				pCurrent->pNext = pNew;
				return;
			}
			counter++;
			pCurrent = pCurrent->pNext;
		}
	}
};