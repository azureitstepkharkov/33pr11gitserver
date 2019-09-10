#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char input;
	bool isDone = false;
	// игровой объект
	TicTacToe game;

	while (isDone == false) {
		game.playGame();
		cout << "Хотели бы вы играть снова? Выберите 'д' - Да, 'н' - Нет : ";
		cin >> input;
		if (input == 'д' || input == 'н') {
			isDone = true;
		}
	}

	system("pause");
	return 0;
}