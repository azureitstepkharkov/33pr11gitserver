#pragma once

using namespace std;
class GameMatrix
{
	int ** matrix;
	int sizeX = 3;
	int sizeY = 3;
protected:
	void startMatrix();
public:
	GameMatrix();
	GameMatrix(int sizeBoard);
	~GameMatrix();

	int **getBoardMatrix();
	int get(int i, int j);

	void set(int i, int j, int value);
	void setX(int i, int j);
	void setO(int i, int j);

	int getSizeX();
	int getSizeY();
	int & operator()(int y, int x)const
	{
		return matrix[y][x];
	};

};