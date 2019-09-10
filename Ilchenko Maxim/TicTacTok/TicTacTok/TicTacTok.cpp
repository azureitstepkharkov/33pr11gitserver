// TicTacTok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Controller.h"

using namespace std;

int main()
{
	bool krest, Win = false;
	int x = 0;
	int y = 0;
	int counter = 0;
	GameMatrix *M = new GameMatrix();
	GameBoard B;
	M->Reset();
	cout << "Chose who go first:" << endl;
	cout << "1 - Krest\n0 - Null" << endl;
	cin >> krest;
	Controller C(krest);
	system("cls");

	while (!Win)
	{
		B.print(M, 3);
		cout << "\n\nNow ";
		if (C.getKrest())
			cout << "krest move\n";
		else
			cout << "null move\n";

		cout << "Set koordinate of your move:\nX = ";
		cin >> x;
		cout << "Y = ";
		cin >> y;
		system("cls");
		if (C.Move(M, x - 1, y - 1))
		{
			counter++;
		}
		else
		{
			cout << "Error: this koordinates is alredy taken or incorrect input\n";
		}
		if (counter >= 4)
		{
			if (C.WinCheck(M))
			{
				Win = true;
				break;
			}
		}
		if (counter >= 9)
		{
			M->Reset();
			counter = 0;
		}
	}
	B.print(M, 3);
	if (!C.getKrest())
		cout << "Krest is Winner!!!\n";
	else
		cout << "Null is Winner!!!\n";
	delete M;
	return 0;
}