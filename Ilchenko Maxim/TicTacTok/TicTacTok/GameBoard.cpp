#include "pch.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;

void GameBoard::print(GameMatrix *m, int size)
{
	cout << "\t  1 2 3\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\t"<<i+1<<" ";
		for (int j = 0; j < size; j++)
		{
			switch (m->get(i,j))
			{
			case 1:
				cout << "X "; break;
			case 2:
				cout << "_ " ; break;
			case 0:
				cout << "O "; break;
			}
		}
		cout << endl;
	}	
}