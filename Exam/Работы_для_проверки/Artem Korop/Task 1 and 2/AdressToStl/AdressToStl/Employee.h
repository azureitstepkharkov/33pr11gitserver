#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

class Employee
{
protected:
	string position;
	string cardAccount;
	int salary;

public:
	Employee();
	~Employee();
};

