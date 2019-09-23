#pragma once
#include"GameMatrix.h"



class GameBoard:public GameMatrix
{
	GameBoard();
	int SizeMS; //������ ����� � �������� default =1
	string cell{'O','X',' '};
	int SizeX;
	int SizeY;
	bool eskapSize() { return true; };

	void drawUp();
	void drawDown();
protected:

public:
	//������ ������� �� �����������, �� ���������
	GameBoard(GameMatrix &mx) ;
	//������ ������� �� �����������, �� ���������, � �������� � ������
	GameBoard(GameMatrix &mx, int sMS) {
		this->SizeX = mx.getSizeX();
		this->SizeY = mx.getSizeY();
		this->SizeMS = sMS;
	};


	void setSizeSM(int size);


	void drawTable(const GameMatrix &mx);

	virtual ~GameBoard() {};

};