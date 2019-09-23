#include "stdafx.h"
#include "GameMatrix.h"


void GameMatrix::startMatrix()
{
	for (int j = 0; j < this->sizeY; j++)
	{
		for (int i = 0; i < this->sizeX; i++)
		{
			this->matrix[j][i] = 2;//это значение при печати будет пустой ячейкой

		}

	}

}

GameMatrix::GameMatrix()
{
	this->sizeX = 3;
	this->sizeY = 3;
	this->matrix = new int*[this->sizeY];
	for (int j = 0; j < this->sizeY; j++)
	{
		this->matrix[j]= new int[this->sizeX];
	}

	this->startMatrix();
}

GameMatrix::GameMatrix(int sizeBoard)
{
	this->sizeX = sizeBoard;
	this->sizeY = sizeBoard;
	this->matrix = new int*[this->sizeY];
	for (int j = 0; j < this->sizeY; j++)
	{
		this->matrix[j] = new int[this->sizeX];
	}

	this->startMatrix();
}


GameMatrix::~GameMatrix()
{
	for (int j = 0; j < this->sizeY; j++)
	{
		delete[] this->matrix[j];
	}
	delete[]this->matrix;
}

int ** GameMatrix::getBoardMatrix()
{
	return this->matrix;
}

int GameMatrix::get(int i, int j)
{
	return this->matrix[j][i];
}

void GameMatrix::set(int i, int j, int value)
{
	if (value <= 2 && value >= 0)
	{
		if(i >= 0 && i < this->sizeX && j >= 0 && j < this->sizeY)	this->matrix[j][i] = value;

		else cout << "Вы вышли за диапазон!!!" << endl;
	}
	else cout << " Вы ввели не правильное значение! " << endl;
}

void GameMatrix::setX(int i, int j)
{
	if (i >= 0 && i < this->sizeX && j >= 0 && j < this->sizeY)	this->matrix[j][i] = 1;

	else cout << "Вы вышли за диапазон!!!" << endl;
}

void GameMatrix::setO(int i, int j)
{
	if (i >= 0 && i < this->sizeX && j >= 0 && j < this->sizeY)	this->matrix[j][i] = 0;

	else cout << "Вы вышли за диапазон!!!" << endl;
}

int GameMatrix::getSizeX()
{
	return this->sizeX;
}

int GameMatrix::getSizeY()
{
	return this->sizeY;
}
