#include "TicTacToe.h"
#include <iostream>

using namespace std;

//����������� �� ���������
TicTacToe::TicTacToe() {}

//���� TicTacToe
void TicTacToe::playGame()
{
	clearBoard();

	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;
	bool isDone = false;

	int x, y; // ���������� � � y

	int turn = 0;

	//���������� ������� ����
	while (isDone == false) {

		//�������� ������� ����
		printBoard();

		// �������� ���������� ��� ����� ������� ���
		x = getX(); // �������� ���������� �
		y = getY(); // �������� ���������� y

		//������ ���
		if (placeMarker(x, y, currentPlayer) == false) {
			//���� ������ ������� ��� ������� ��������� 
			cout << "��� ������ ������!\n";
		}
		else {
			// � ��������� ������ �� ������� ������� ���� ���
			turn++;
			//������� �� �����
			if (checkForVictory(currentPlayer) == true) {
				//�������� �������!
				cout << "����� ����! ����� " << currentPlayer << " �������!\n";
				isDone = true;
			}
			else if (turn == 9) {
				
				cout << "�����!\n";
				isDone = true;
			}

			//������� �������
			if (currentPlayer == player1) {
				cout << "-----------------------" << endl;
				cout << "����� 2" << endl;
				currentPlayer = player2;

			}
			else {
				cout << "-----------------------" << endl;
				cout << "����� 1" << endl;
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
		cout << "������� X ����������: ";
		cin >> x;

		if (x < 1 || x > 3) {
			cout << "�� ����� �� ������ ����������!\n";
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
		cout << "������� Y ����������: ";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "�� ����� �� ������ ����������!\n";
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
	//��������� ������
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true; //�� ��������!
		}
	}

	//��������� �������
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true; //�� ��������!
		}
	}

	//��������� ����� ���������
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true; // �� ��������!
	}

	//��������� ������ ���������
	if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return true; // �� ��������!
	}

	return false;
}

void TicTacToe::clearBoard()
{
	//������� ������� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	//����������� ������� ����
	cout << endl;
	cout << " |1 2 3|\n";
	for (int i = 0; i < 3; i++) 
	{
		cout << " -------\n";
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	cout << " -------\n";
}