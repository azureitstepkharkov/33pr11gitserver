#include "GameBoard.h"





void GameBoard::drawUp()
{

	cout << "\n      X" << (char)26 << "\n  Y";

	for (int i = 1; i <= this->SizeX; i++)
	{
		cout << " ";
		cout.width(this->SizeMS + 1);
		cout << i << " ";

	}//номера ячеек массива
	cout << endl << "  " << (char)25;//arrow down
	for (int l = 0; l < this->SizeX; l++)
	{
		if (l == 0) {
			cout << (char)201 << (char)205;
			for (int c = 0; c < this->SizeMS; c++)cout << (char)205;
			cout << (char)205;
		}

		else {
			cout << (char)209 << (char)205;
			for (int c = 0; c < this->SizeMS; c++)cout << (char)205;
			cout << (char)205;
		}


	}cout << (char)187 << endl;


}


void GameBoard::drawTable(int** &matrix)
{
	
		this->drawUp();

		for (int j = 0; j < this->SizeY; j++)//основа массива
		{

			cout << "  " << j + 1 << (char)186;//это номер строки и правая черта

			for (int x = 0; x < this->SizeX; x++)	cout << " " <<this->sign[ matrix[j][x]] << " " << (char)179;//печать символов и перегородок

			cout << "\b" << (char)186 << endl;

			if (j < this->SizeY - 1) {

				cout << "   " << (char)199;
				for (int l = 0; l < this->SizeX; l++)
				{
					cout << (char)196;
					for (int c = 0; c < this->SizeMS; c++)cout << (char)196;
					cout << (char)196 << (char)197;
				}

				cout << "\b" << (char)182 << endl;
			}
		}

		this->drawDown();
	
};


void GameBoard::drawDown()
{

	cout << "   " << (char)200 << (char)205;
	for (int c = 0; c < this->SizeMS; c++)cout << (char)205;
	cout << (char)205;

	for (int l = 1; l < this->SizeX; l++) {
		cout << (char)207 << (char)205;
		for (int c = 0; c < this->SizeMS; c++)cout << (char)205;
		cout << (char)205;
	}

	cout << (char)188 << endl;
}

void GameBoard::print(GameMatrix & matrix)
{
	//this->drawTable(matrix.getBoardMatrix());
}

#include "stdafx.h"