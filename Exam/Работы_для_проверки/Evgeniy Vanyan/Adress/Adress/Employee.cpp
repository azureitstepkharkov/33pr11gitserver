#include "pch.h"
#include "Employee.h"


Employee::Employee(string position, double bankcard, double salary)
{
	this->position = position;
	this->bankcard = bankcard;
	this->salary = salary;
}

Employee::~Employee()
{
}
