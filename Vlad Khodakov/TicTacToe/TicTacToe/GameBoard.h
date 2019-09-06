#pragma once
#include"GameMatrix.h"
#include "stdafx.h"


struct GameBoard
{
	void print(GameMatrix& matrix);

	

private:
	string sign{ 'X','O',' ' };
	int SizeMS; //размер €чеек в символах default =1
	int SizeX;//количество €чеек в таблице по горизонтале
	int SizeY;//количество €чеек в таблице по вертикале

	

	void drawUp();
	void drawDown();
	void drawTable( int **  & matrix);
};

