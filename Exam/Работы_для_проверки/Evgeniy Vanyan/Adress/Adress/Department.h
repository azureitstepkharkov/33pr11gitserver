#pragma once
#include "Employee.h"
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>
using namespace std;
class Department: Employee
{
private:
	Department() {};
	Department(const Department& obj) {};
protected:
	string NameDepartment;
	list <Department>ListEmployees;
	string Head_of_Department;
public:
	Department(string NameDepartment, string ListEmployees, string Head_of_Department);
	friend ostream& operator<<(ostream& os, Department info)
	{
		os << " NameDepartment: " << info.NameDepartment
			//<< " List Employees: " << info.ListEmployees
			<< " Head of Department: " << info.Head_of_Department
			<< endl;
		return os;
	}
	~Department();
};

