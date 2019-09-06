// TicTacToeMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;
class GameMatrix
{
private:
	int ** matrix;
	const int n = 3;
	const int m = 3;
	GameMatrix(const GameMatrix & obj) {}
public:
	GameMatrix()
	{
		this->matrix = new int*[n];
		for (int i = 0; i < 3; i++)
			matrix[i] = new int[m];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = 2;
			}
		}

	}
	void generate()
	{
		const int a = 0;
		const int b = 2;

		this->matrix = new int*[n];
		for (int i = 0; i < 3; i++)
			matrix[i] = new int[m];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				matrix[i][j] = rand() % (b - a + 1) + a;;

			}
		}
	}
	int getItem(int i, int j)
	{
		return matrix[i][j];
	}
	void setItem(int i, int j, int value)
	{
		matrix[i][j] = value;
	}
	void Print(GameMatrix & matrix)
	{
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++)
			{
				cout << matrix.getItem(i,j) << " ";
			}
			cout << endl;
		}
	}

	GameMatrix getMatrix(GameMatrix matrix)
	{
		return matrix;
	}

	~GameMatrix()
	{
		for (int i = 0; i < 3; i++)
		{
			delete matrix[i];
		}
		delete[] matrix;
	}
	
	friend ostream& operator << (ostream & os,  GameMatrix& matrix)
	{
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++)
			{
				cout << matrix.getItem(i, j) << " ";
			}
			cout << endl;
		}
		return os;
	}


	friend bool operator < (GameMatrix   &a,   GameMatrix &b)
	{
		int  sumA = 0;
		int  sumB = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				sumA = sumA + a.getItem(i,j);

			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				sumB = sumB + b.getItem(i, j);

			}
		}

		if (sumA > sumB)
		{
			return true;
		}
		else return false;

	}
};


int main()
{
	
		GameMatrix * Game = new GameMatrix();
		Game->generate();
		
		

		delete Game;
		system("pause");
		
    return 0;
}

