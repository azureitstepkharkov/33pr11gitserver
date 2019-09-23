
#include "stdafx.h"
#include "GameMatrix.h"
#include "GameBoard.h"
#include "TicTacToe.h"


int main()
{
	
	TicTacToe one;

	
	GameBoard gamer2(one);
	gamer2.drawTable(one);

	return 0;
}

