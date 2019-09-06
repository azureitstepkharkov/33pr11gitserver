#include "pch.h"
#include "Controller.h"

const int N = 3;

bool Controller::Move(GameMatrix *M,int x, int y)
{
	if (IsEmpty(M, x, y))
	{
		if (Krest)
		{
			M->set(x, y, 1);
			Krest = false;
			return true;
		}
		else
		{
			M->set(x, y, 0);
			Krest = true;
			return true;
		}
	}
	else
		return false;
}

void Controller::setKrest(bool k)
{
	Krest = k;
}

bool Controller::getKrest()
{
	return Krest;
}

bool Controller::IsEmpty(GameMatrix *M, int x,int y)
{
	if (M->get(x, y) == 2 && x < N && y < N && x >= 0 && y >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Controller::WinCheck(GameMatrix *M)
{
	int w = 4;
	if (Krest)
	{
		w = 0;
	}
	else
	{
		w = 1;
	}
	//hor
	if (M->get(0, 0) == w && M->get(0, 1) == w && M->get(0, 2) == w) return true;
	else if (M->get(1, 0) == w && M->get(1, 1) == w && M->get(1, 2) == w) return true;
	else if (M->get(2, 0) == w && M->get(2, 1) == w && M->get(2, 2) == w) return true;
	//ver
	else if (M->get(0, 0) == w && M->get(1, 0) == w && M->get(2, 0) == w) return true;
	else if (M->get(0, 1) == w && M->get(1, 1) == w && M->get(2, 1) == w) return true;
	else if (M->get(0, 2) == w && M->get(1, 2) == w && M->get(2, 2) == w) return true;
	//diag
	else if (M->get(0, 0) == w && M->get(1, 1) == w && M->get(2, 2) == w) return true;
	else if (M->get(2, 0) == w && M->get(1, 1) == w && M->get(0, 2) == w) return true;
	else return false;
}

Controller::Controller(bool Kr)
{
	Krest = Kr;
}

Controller::Controller()
{
	Krest = true;
}


Controller::~Controller()
{
}
