#pragma once
#include "GameMatrix.h"
#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;
class GameBoard :public GameMatrix
{
public:
	void Print(GameMatrix * matrix )
	{
		for (int i = 0; i < 3; i++) {
			
			for (int j = 0; j < 3; j++)
			{
				if (matrix->getValue(i,j) == 0)
				{
					cout << "O ";
				}
				if (matrix->getValue(i, j) == 1)
				{
					cout << "X ";
				}
				if (matrix->getValue(i, j) == 2)
				{
					cout << "_ ";
				}
			}
			cout << endl;
		}
	}

	friend ostream& operator << (ostream & os, GameMatrix& matrix)
	{
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++)
			{
				cout << matrix.getValue(i, j) << " ";
			}
			cout << endl;
		}
		return os;
	}

	friend bool operator< (GameMatrix& a, GameMatrix& b) {
		int first = 0;
		int second = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++){
				first += a.getValue(i,j);
				second += b.getValue(i,j);
			}
		}
		return first < second;
	};

};

