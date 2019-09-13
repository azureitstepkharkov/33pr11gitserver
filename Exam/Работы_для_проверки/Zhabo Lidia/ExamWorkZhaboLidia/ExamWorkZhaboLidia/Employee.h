#pragma once
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Employee
{
private:
	string position;
	string cardNum;
	float salary;
public:
	Employee(string position,
			string cardNum,
			float salary)
	{
		this->position = position;
		this->cardNum = cardNum;
		this->salary = salary;
	}

	Employee() {};
	~Employee() {};
};

