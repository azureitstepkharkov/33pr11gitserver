#pragma once
#include<iostream>
#include<string>
#include"Employee.h"

using namespace std;

class Department
{
protected:
	string DepartmentName;
	Employee* EmployeesList;
	Employee* Cheif;

	Department() {};
	Department(Department& dep) {};
public:

	/*Department(string depname, string pos, string acc, string salary, string phone, string ct, string tpstrt, string strt, string hsnum,
		unsigned int apart, string name, string surname, string sex, unsigned int age);*/

	friend ostream& operator<<(ostream& out_data, Department& data);

	
	~Department() {};
};
