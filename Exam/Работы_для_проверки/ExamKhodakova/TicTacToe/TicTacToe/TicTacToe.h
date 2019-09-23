#pragma once
#include"stdafx.h"
class TicTacToe:public GameMatrix
{
	
	short progress;
	short win;


	bool analysisVertical(int& winner);
	bool analysisGorizontal(int& winner);
	bool analysisDiagonalLift(int& winner);
	bool analysisDiagonalRight(int& winner);
public:
	TicTacToe() {
		this->progress = getSizeX()*getSizeY();
		this->win = 3;
	};
	TicTacToe(int sizeBoard) :GameMatrix(sizeBoard){
		this->progress = getSizeX()*getSizeY();
		this->win = 5;
	};
	~TicTacToe() {};
	int getProgress();



	bool endGame();
	bool winGame(int& winner);
};




void findSeqUnits(bool **arr, int row, int col, int&x, int&y, bool course)
{
	int count = 0, countMax = 0;

	for (int i = 0; i < row&&countMax != row; i++)
	{
		count = 0;
		for (int j = 0; j < col; j++)
		{
			if (course)//ищет по горизонтали
			{
				if (arr[i][j])
				{
					count++;
				}
				if (!(arr[i][j]))
				{
					if (count > countMax)
					{
						countMax = count;
						y = i;
						x = j - count;
					}
					count = 0;
				}
				if (i == row - 1 || j == col - 1)
				{
					if (count > countMax)
					{
						countMax = count;
						y = i;
						x = j - count + 1;
					}
				}
				if (count == row)
				{
					countMax = count;
					y = i;
					x = j - count + 1;
				}
			}
			else //по вертикали ищет 
			{
				if (arr[j][i])
				{
					count++;
				}
				if (!(arr[j][i]))
				{
					if (count > countMax)
					{
						countMax = count;
						x = i;
						y = j - count;
					}
					count = 0;
				}
				if (i == row - 1 || j == col - 1)
				{
					if (count > countMax)
					{
						countMax = count;
						x = i;
						y = j - count + 1;
					}

				}
				if (count == col)
				{
					countMax = count;
					x = i;
					y = j - count + 1;
				}
			}
		}

	}
	y++;
	x++;

}



