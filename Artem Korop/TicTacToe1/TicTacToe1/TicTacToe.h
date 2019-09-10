#pragma once

class TicTacToe
{
public:
	//����������� �� ���������
	TicTacToe();

	// ������� ���� � ����
	void playGame();

private:

	//�������� ���� �� ������������
	int getX();
	int getY();
	//������ ���. ���� �� ���������� ����, �� �� ����� ������� ���!
	bool placeMarker(int x, int y, char currentPlayer);

	//���������� true, ���� ������� ����� �������!
	bool checkForVictory(char currentPlayer);

	//������� ������� ������� ����
	void clearBoard();
	// ������� �������� ������� ����
	void printBoard();

	//������ ��������� �������� ����
	char board[3][3];
};