#pragma once
#include "Person.h"
#include <string>
using namespace std;
class Employee: Person
{
private:
	//Employee() {};
	Employee(const Employee& obj) {};
protected:
	string position;
	double bankcard;
	double salary;
public:
	Employee() {};
	Employee(string position, double bankcard, double salary);
	friend ostream& operator<<(ostream& os, Employee info)
	{
		os << " Position: " << info.position
			<< " BankCard: " << info.bankcard
			<< " Salary: " << info.salary
			<< endl;
		return os;
	}

	~Employee();
};

