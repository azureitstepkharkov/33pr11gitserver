#include "stdafx.h"
#include "GameMatrix.h"


void GameMatrix::startMatrix()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			this->matrix[i][j] = 2;

		}

	}

}

GameMatrix::GameMatrix()
{
	this->matrix = new int*[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->matrix[i]= new int[this->size];
	}

	this->startMatrix();
}


GameMatrix::~GameMatrix()
{
	for (int i = 0; i < this->size; i++)
	{
		delete[] this->matrix[i];
	}
	delete[]this->matrix;
}

int ** GameMatrix::getBoardMatrix()
{
	return this->matrix;
}

int GameMatrix::get(int i, int j)
{
	return this->matrix[i][j];
}

void GameMatrix::set(int i, int j, int value)
{
	if (value <= 2 && value >= 0)
	{

		this->matrix[i][j] = value;

	}
	else cout << " Вы ввели не правильное значение! " << endl;
}

int GameMatrix::SizeM()
{
	return this->size;
}

