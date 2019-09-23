
#include"stdafx.h"
#include"TicTacToe.h"



bool TicTacToe::analysisVertical(int & winner)
{
	for (int y = 0; y < (this->sizeY - (this->win - 1)); y++)
	{
		for (int x = 0; x < this->sizeX ; x++)
		{
			if (this->win == 3)
				if (this->matrix[y][x] != 2
					&& this->matrix[y][x] == this->matrix[y + 1][x]
					&& this->matrix[y + 2][x] == this->matrix[y + 1][x]
					)//победа по вертикали на 3
				{
					winner = this->matrix[y][x];
					return true;
				}
				else {}
			else {
				if (this->matrix[y][x] != 2
					&& this->matrix[y][x] == this->matrix[y + 1][x]
					&& this->matrix[y + 2][x] == this->matrix[y + 1][x]
					&& this->matrix[y + 3][x] == this->matrix[y + 1][x]
					&& this->matrix[y + 4][x] == this->matrix[y + 1][x]
					)//победа по вертикали на 5
				{
					winner = this->matrix[y][x];
					return true;
				}
				else {}
			
			}
		}
	}
	return false;
}



bool TicTacToe::analysisGorizontal(int & winner)
{

	for (int y = 0; y < this->sizeY ; y++)
	{

		for (int x = 0; x < (this->sizeX - (this->win - 1)); x++)
		{
			if (this->win == 3)
				if (this->matrix[y][x] != 2
					&& this->matrix[y][x] == this->matrix[y ][x + 1]
					&& this->matrix[y][x + 2] == this->matrix[y][x + 1]
					)//победа по горизонтали на 3
				{
					winner = this->matrix[y][x];
					return true;
				}
				else {}
			else {
				if (this->matrix[y][x] != 2
					&& this->matrix[y][x] == this->matrix[y][x + 1]
					&& this->matrix[y][x + 2] == this->matrix[y][x + 1]
					&& this->matrix[y][x + 3] == this->matrix[y][x + 1]
					&& this->matrix[y][x + 4] == this->matrix[y][x + 1]
					)//победа по горизонтали на 5
				{
					winner = this->matrix[y][x];
					return true;
				}
				else {}
			
			
			}
		}
	}
	return false;
}

bool TicTacToe::analysisDiagonalLift(int & winner)// влево то есть \      */
{
	for (int y = 0; y < (this->sizeY - (this->win - 1)); y++)
	{
		for (int x = 0; x < (this->sizeX - (this->win - 1)); x++)
		{

			if (this->win == 3)
				if (this->matrix[y+1][x+1] != 2
					&& this->matrix[y][x] == this->matrix[y+1][x + 1]
					&& this->matrix[y+2][x + 2] == this->matrix[y+1][x + 1]
					)//победа по диагонали  влево то есть \      на 3*/
				{
					winner = this->matrix[y+1][x+1];
					return true;
				}
				else {}
			else {
				if (this->matrix[y+2][x+2] != 2
					&& this->matrix[y][x] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 1][x + 1] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 3][x + 3] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 4][x + 4] == this->matrix[y + 2][x + 2]
					)//победа по диагонали  влево то есть \      на 5*/
				{
					winner = this->matrix[y+2][x+2];
					return true;
				}
				else {}
			
			}
		}
	}
	return false;
}

bool TicTacToe::analysisDiagonalRight(int & winner)// вправо то есть /       
{
	for (int y = 0; y < (this->sizeY - (this->win - 1)); y++)
	{
		for (int x = 0; x < (this->sizeX - (this->win - 1)); x++)
		{

			if (this->win == 3)
				if (this->matrix[y+1][x+1] != 2
					&& this->matrix[y][x+2] == this->matrix[y + 1][x + 1]
					&& this->matrix[y + 2][x] == this->matrix[y + 1][x + 1]
					)//победа по диагонали вправо то есть / на 3
				{
					winner = this->matrix[y+1][x+1];
					return true;
				}
				else {}

			else {//для победы из 5 символов
				if (this->matrix[y+2][x+2] != 2
					&& this->matrix[y][x + 4] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 1][x+3] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 3][x+1] == this->matrix[y + 2][x + 2]
					&& this->matrix[y + 4][x] == this->matrix[y + 2][x + 2]
					)//победа по диагонали вправо то есть / на 5 
				{
					winner = this->matrix[y + 2][x + 2];
					return true;
				}
				else {}

			}
		}
	}
	return false;
}



int TicTacToe::getProgress()
{
	return (int)this->progress;
}



bool TicTacToe::endGame()
{

	return false;
}

bool TicTacToe::winGame(int& winner)
{
	


	
	
	return false;
}


