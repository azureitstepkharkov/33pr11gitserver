// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameMatrix.h"
#include "GameBoard.h"


int main()
{
	GameMatrix game;


	GameBoard gamer(game);

	gamer.drawTable(game);
	game.setO(0, 2);
	game.setX(1, 1);
	gamer.drawTable(game);
	
    return 0;
}

