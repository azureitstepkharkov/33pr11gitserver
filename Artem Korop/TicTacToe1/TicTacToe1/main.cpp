#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char input;
	bool isDone = false;
	// ������� ������
	TicTacToe game;

	while (isDone == false) {
		game.playGame();
		cout << "������ �� �� ������ �����? �������� '�' - ��, '�' - ��� : ";
		cin >> input;
		if (input == '�' || input == '�') {
			isDone = true;
		}
	}

	system("pause");
	return 0;
}