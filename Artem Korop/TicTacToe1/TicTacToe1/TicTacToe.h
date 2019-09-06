#pragma once

class TicTacToe
{
public:
	//Конструктор по умолчанию
	TicTacToe();

	// Функция игра в игру
	void playGame();

private:

	//Получаем ввод от пользователя
	int getX();
	int getY();
	//Делает ход. Если он возвращает ложь, он не может сделать ход!
	bool placeMarker(int x, int y, char currentPlayer);

	//Возвращает true, если текущий игрок выиграл!
	bool checkForVictory(char currentPlayer);

	//Функция очищает игровое поле
	void clearBoard();
	// Функция печатает игровое поле
	void printBoard();

	//Хранит состояние игрового поля
	char board[3][3];
};