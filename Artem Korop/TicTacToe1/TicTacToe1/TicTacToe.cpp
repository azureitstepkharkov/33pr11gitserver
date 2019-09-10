#include "TicTacToe.h"
#include <iostream>

using namespace std;

//Конструктор по умолчанию
TicTacToe::TicTacToe() {}

//Игра TicTacToe
void TicTacToe::playGame()
{
	clearBoard();

	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;
	bool isDone = false;

	int x, y; // координаты х и y

	int turn = 0;

	//Внутренний игровой цикл
	while (isDone == false) {

		//Печатаем игровое поле
		printBoard();

		// Получить координаты где игрок сделает ход
		x = getX(); // получаем координаты х
		y = getY(); // получаем координаты y

		//Делаем ход
		if (placeMarker(x, y, currentPlayer) == false) {
			//Если нельзя сделать ход выводим сообщение 
			cout << "Эта ячейка занята!\n";
		}
		else {
			// В противном случае мы успешно сделали этот ход
			turn++;
			//выиграл ли игрок
			if (checkForVictory(currentPlayer) == true) {
				//Соперник победил!
				cout << "Конец игры! Игрок " << currentPlayer << " победил!\n";
				isDone = true;
			}
			else if (turn == 9) {
				
				cout << "Ничья!\n";
				isDone = true;
			}

			//Сменить игроков
			if (currentPlayer == player1) {
				cout << "-----------------------" << endl;
				cout << "Игрок 2" << endl;
				currentPlayer = player2;

			}
			else {
				cout << "-----------------------" << endl;
				cout << "Игрок 1" << endl;
				currentPlayer = player1;
			}
		}
	}
}



int TicTacToe::getX()
{
	bool isInputBad = true;

	int x;

	while (isInputBad == true) {
		cout << "Введите X координаты: ";
		cin >> x;

		if (x < 1 || x > 3) {
			cout << "Вы ввели не верные координаты!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return x - 1;
}

int TicTacToe::getY()
{
	bool isInputBad = true;

	int y;

	while (isInputBad == true) {
		cout << "Введите Y координаты: ";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "Вы ввели не верные координаты!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y - 1;
}

bool TicTacToe::placeMarker(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		return false;
	}

	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToe::checkForVictory(char currentPlayer)
{
	//Проверяем строки
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true; //Мы победили!
		}
	}

	//Проверяем столбцы
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true; //Мы победили!
		}
	}

	//Проверяем левую диагональ
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true; // Мы победили!
	}

	//Проверяем правую диагональ
	if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return true; // Мы победили!
	}

	return false;
}

void TicTacToe::clearBoard()
{
	//Очищаем игровое поле
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	//заполненяем игровое поле
	cout << endl;
	cout << " |1 2 3|\n";
	for (int i = 0; i < 3; i++) 
	{
		cout << " -------\n";
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	cout << " -------\n";
}