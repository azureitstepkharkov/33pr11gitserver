#pragma once
#include<random>

class GameMatrix
{
private:
	int ** matrix;
	const int n = 3;
	const int m = 3;
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
	int getValue(int i, int j)
	{
		return matrix[i][j];
	}
	void setValue(int i, int j, int value)
	{
		matrix[i][j] = value;
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
};

