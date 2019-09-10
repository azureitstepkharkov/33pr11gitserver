#pragma once
#include "GameMatrix.h"
#include "GameBoard.h"
class Controller
{
private:
	bool Krest;
public:
	bool WinCheck(GameMatrix *M);
	bool Move(GameMatrix *M, int x, int y);
	bool IsEmpty(GameMatrix *M, int x, int y);
	void setKrest(bool k);
	bool getKrest();
	Controller(bool Kr);
	Controller();
	~Controller();
};

