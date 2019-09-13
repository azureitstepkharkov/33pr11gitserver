#pragma once
#include"pch.h"

class Department : public Employee
{
protected:
	string departmentName;
	list<Employee*> emploeeList;
	string headOfDepartment;
	Department() {};
	Department(const Department& obj) { cout << "Department& obj" << endl; };
public:
	Department(string departmentName_value, string headOfDepartment_value) {	//add list<Employee>
		this->departmentName = departmentName_value;
		this->headOfDepartment = headOfDepartment_value;
	};

	void setDepartmentName(string departmentName_value) { this->departmentName = departmentName_value; };
	void setHeadOfDepartment(string headOfDepartment_value) { this->headOfDepartment = headOfDepartment_value; };
	string getDepartmentName() { return departmentName; };
	string getHeadOfDepartment() { return headOfDepartment; };

	/*void printEmployees()
	{
		for_each(emploeeList.begin(), emploeeList.end(), printEmployee);
	}*/

	void newEmployee(string position, int BankCardAccount, double salary)
	{
		Employee* m = new Employee(position, BankCardAccount, salary);
		emploeeList.push_back(m);
	}

	friend ostream& operator<< (ostream& os, Department& data)
	{
		os << "DepartmentName = " << data.departmentName << ", Head Of Department = " << data.headOfDepartment << endl; /*", Employees = " << data.printEmploeeList() << */
		return os;
	}

	~Department() {};
};

