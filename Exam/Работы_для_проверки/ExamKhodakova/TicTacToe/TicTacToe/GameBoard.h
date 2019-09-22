#pragma once
#include"GameMatrix.h"
#include <Windows.h>


struct GameBoard
{

	void print(GameMatrix& matrix)
	{
	
		for (int j = 0; j < matrix.SizeY(); j++)
		{
			for (int i = 0; i < matrix.SizeX(); i++)
			{

				cout<<matrix.get(j, i);

			}
			cout << endl;
		}
	
	
	}


};

//вывод на экран массива




//void printArray(float arr[], int size, int a, int b)
//{
//	int SIM = 0;
//	if (a < fabs(arr[0]))
//	{
//		a = arr[0];
//		while (a > 0)
//		{
//			a /= 10;
//			SIM++;
//		}
//	}
//	else if (a > b)
//	{
//		while (a > 0)
//		{
//			a /= 10;
//			SIM++;
//		}
//	}
//	else
//	{
//		while (b > 0)
//		{
//			b /= 10;
//			SIM++;
//		}
//	}
//	SIM += 5;
//
//
//	cout << " ";
//	for (int i = 1; i <= size; i++)//номера €чеек массива
//	{
//		cout.width(SIM);
//		cout << i;
//	}
//	cout << endl;
//
//
//	cout << "  -";
//	for (int i = 0; i < size; i++)
//	{
//		for (int i = 0; i < SIM; i++)
//		{
//			cout << "-";
//		}
//	}
//	cout << endl;
//
//	cout << "  |";
//	for (int i = 0; i < size; i++)
//	{
//		cout.width(SIM - 2);
//		cout << arr[i];
//		cout << " |";
//	}
//	//cout << "|";
//	cout << endl;
//
//
//	cout << "  -";
//	for (int i = 0; i < size; i++)
//	{
//		for (int i = 0; i < SIM; i++)
//		{
//			cout << "-";
//		}
//
//	}
//	cout << endl;
//
//}
//



//void printArrInt2(GameMatrix &game, int row, int col)
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(866);
//	int buf = 0;
//	int count = 0;
//	int f = 0;
//	count = 0;
//
//	int SIM = count + 3;
//	cout << "\n      X" << (char)26;
//	cout << "\n  Y" << endl;
//	/*delete buf;
//	delete count;*/
//	cout << "  " << (char)25 << "   ";
//	for (int i = 1; i <= col; i++)//номера €чеек массива
//	{
//		if (i == 10)cout << " ";
//		f = count + 1;
//		while (f > 1)
//		{
//			cout << " ";
//			f--;
//		}
//
//		cout << i;
//		f = count + 1;
//		while (f > 1)
//		{
//			cout << " ";
//			f--;
//		}
//	}
//	cout << endl;
//
//	for (int i = 0; i < row; i++)//основа массива
//	{
//
//
//		cout.width(SIM);
//		cout << "   ";
//		for (int l = 0; l < col&&i == 0; l++)
//		{
//
//			if (i == 0 && l == 0)
//			{
//				cout << (char)201 << (char)205 << (char)205 << (char)205;
//			}
//			else
//			{
//				cout << (char)209 << (char)205 << (char)205 << (char)205;
//			}
//			f = count;
//			while (f > 1)
//			{
//				cout << (char)205;
//				f--;
//			}
//		}
//		if (i == 0)
//		{
//			cout << (char)187;
//		}
//		cout << endl;
//
//		cout.width(SIM);
//		cout << i + 1;
//		cout << (char)186;
//		for (int j = 0; j < col; j++)
//		{
//
//			cout << " " << game.get(i,j) << " " << (char)179;
//
//		}
//		cout << "\b" << (char)186;
//		cout << endl;
//
//
//
//		cout.width(SIM);
//		cout << "   " << (char)199;
//		for (int l = 0; l < col; l++)
//		{
//			if (i == row - 1 && l == 0)
//			{
//				cout << "\b" << (char)200 << (char)205 << (char)205 << (char)205;
//				f = count;
//				while (f > 1)
//				{
//					cout << (char)205;
//					f--;
//				}
//			}
//			else if (i == row - 1)
//			{
//				cout << (char)207 << (char)205 << (char)205 << (char)205;
//				f = count;
//				while (f > 1)
//				{
//					cout << (char)205;
//					f--;
//				}
//			}
//			else {
//				f = count;
//				while (f > 1)
//				{
//					cout << (char)196;
//					f--;
//				}
//				cout << (char)196 << (char)196 << (char)196 << (char)197;
//
//			}
//
//		}
//
//		if (i == row - 1)
//		{
//			cout << (char)188;
//		}
//		else
//		{
//			cout << "\b" << (char)182;
//		}
//	}
//	cout << endl;
//	SetConsoleCP(866);
//}
