#pragma once
class Matrix
{
private:
	Matrix(const Matrix&obj){}

public:
	int **x;
	int count = 3;
	int value = 3;
	Matrix();
	Matrix(int size, int count);
	void getMatrix();
	~Matrix();
};

