#include "pch.h"
#include "Controller.h"
#include "GameMatrix.h"
#include "random"
#include <ctime>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, GameMatrix& t)
{
	for (int i = 0; i < t.getSize(); i++)
	{
		for (int j = 0; j < t.getSize(); j++)
		{
			os << t.get(i, j);
		}
	}
	return os;
}
bool operator< (GameMatrix& a, GameMatrix& b)
{
	return a.getSize() < b.getSize();
};
GameMatrix::GameMatrix(int x, int y, int v)
{
	Matrix = new int*[x];
	for (int i = 0; i < y; i++)
	{
		Matrix[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0;  j < y;  j++)
		{
			Matrix[i][j] = v;
		}
	}
	N = x > y;
}
GameMatrix::GameMatrix()
{
	N = 3;
	Matrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Matrix[i] = new int[N];
	}
}
int GameMatrix::get(int x, int y)
{
	if (x < N && y < N && x >= 0 && y >= 0)
	{
		return Matrix[x][y];
	}
}
void GameMatrix::set(int x, int y, int v)
{
	if (x < N && y < N && x >= 0 && y >= 0)
	{
		Matrix[x][y] = v;
	}
}

void GameMatrix::Reset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Matrix[i][j] = 2;
		}
	}
}

void GameMatrix::generate()
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Matrix[i][j] = rand() % 3;
		}
	}
}

GameMatrix::~GameMatrix()
{
	for (int i = 0; i < N; i++)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
}
