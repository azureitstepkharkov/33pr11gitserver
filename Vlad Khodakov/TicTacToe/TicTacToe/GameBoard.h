#pragma once
#include"GameMatrix.h"
#include "stdafx.h"


struct GameBoard
{
	void print(GameMatrix& matrix);

	

private:
	string sign{ 'X','O',' ' };
	int SizeMS; //������ ����� � �������� default =1
	int SizeX;//���������� ����� � ������� �� �����������
	int SizeY;//���������� ����� � ������� �� ���������

	

	void drawUp();
	void drawDown();
	void drawTable( int **  & matrix);
};

