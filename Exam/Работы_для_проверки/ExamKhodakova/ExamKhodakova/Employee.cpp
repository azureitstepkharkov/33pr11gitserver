#include "stdafx.h"
#include "Employee.h"





Employee::~Employee()
{
}

//Employee::Employee(string pos, string acc, string salary, string phone, string ct, string tpstrt, string strt, string hsnum, unsigned int apart, string name, string surname, string sex, unsigned int age)
//{
//	this->Position = pos;
//	this->BankAccount = acc;
//	this->Salary = salary;
//}

ostream & operator<<(ostream & out_data, Employee & empl)
{
	out_data << empl.Position << " " << empl.BankAccount << " " << empl.Salary
		<< endl;

	return out_data;
}