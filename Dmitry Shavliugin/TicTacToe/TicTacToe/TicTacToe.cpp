// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"GameBoard.h"
#include"GameMatrix.h"

using namespace std;

int main()
{
	GameMatrix * Game = new GameMatrix();
	Game->generate();
	GameBoard * Board = new GameBoard();
	GameBoard * Board2 = new GameBoard();
	//Board->Print(Game);

	delete Game;
	delete Board;
	system("pause");
    return 0;
}

