#pragma once
#include<iostream>
using namespace std;
class GameMatrix
{
	int ** matrix;
	const int sizeX = 3;
	const int sizeY = 3;
	void startMatrix();
public:
	GameMatrix();
	~GameMatrix();

	int **getBoardMatrix();
	int get(int i, int j);
	void set(int i, int j, int value);
	void setX(int i, int j);
	void setO(int i, int j);
	int SizeX();
	int SizeY();

};