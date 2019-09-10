#pragma once
#include<iostream>
using namespace std;
class GameMatrix
{
	int ** matrix;
	const int size = 3;
	void startMatrix();
public:
	GameMatrix();
	~GameMatrix();

	int **getBoardMatrix();
	int get(int i, int j);
	void set(int i, int j, int value);
	int SizeM();

};