#include "pch.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	x = new int*[value];
	for (int i = 0; i < count; i++) {
		x[i] = new int[value];
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
		{
			x[i][j] = 2;
		}
	}
}
Matrix::Matrix(int size, int count)
{
	value = size;
	
	x = new int*[value];
	for (int i = 0; i < count; i++) {
		x[i] = new int[value];
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
		{
			x[i][j] = 2;
		}
	}
}
void Matrix::getMatrix()
{
	
	for (int i = 0; i < count; i++) {
		cout << endl;
		for (int j = 0; j < count; j++) {
			cout << x[i][j] << ' ';
		}
	}
	cout << endl;
}

Matrix::~Matrix()
{
	
	for (int i = 0; i < count; i++)
	{
		delete x[i];
	}
	delete[] x;
}

class Fish
{ 
	//конструтор копирования закрыть

};