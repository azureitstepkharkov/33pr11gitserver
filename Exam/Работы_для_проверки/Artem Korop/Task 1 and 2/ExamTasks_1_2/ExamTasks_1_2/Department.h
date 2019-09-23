#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>
#include "HumanEntity.h"

using namespace std;

class Department
{
protected:

	string DepartmentName;
	string EmployeesList;
	string BossDepartment;

	Department()
	{

	};

private:

	// Constructor Copy
	Department(Department& obj)
	{
		cout << "call Constructor Copy Department" << endl;
	}

public:

	Department(string DepartmentName, string EmployeesList, string BossDepartment)
	{
		this->DepartmentName = DepartmentName;
		this->EmployeesList = EmployeesList;
		this->BossDepartment = BossDepartment;
	}

	// Destructor
	~Department() 
	{
		cout << "call Destructor Department" << endl;
	};

	// сеттер
	void setDepartmentName(string DepartmentName)
	{
		this->DepartmentName = DepartmentName;
	}

	// геттер
	string getDepartmentName()
	{
		return this->DepartmentName;
	}

	Department& operator = (const Department& obj) {
		this->DepartmentName = obj.DepartmentName;
		this->EmployeesList = obj.EmployeesList;
		this->BossDepartment = obj.BossDepartment;
		return *this;
	}
	// прототип перегрузка оператора <<
	friend ostream& operator<< (ostream& os, const Department& t);
};

// перегрузка оператора <<
 ostream& operator<< (ostream& os, const Department& t)
{
	os << "DepartmentName   = " << t.DepartmentName << "EmployeesList = " << t.EmployeesList << "BossDepartment = " << t.BossDepartment;
	return os;
}

