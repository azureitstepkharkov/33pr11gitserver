#pragma once
#include"pch.h"

class Department : public Employee
{
protected:
	string departmentName;
	list<Employee*> employeeList;
	string headOfDepartment;
	Department() {};
	Department(const Department& obj) { cout << "Department& obj" << endl; };
public:
	Department(string departmentName_value, string headOfDepartment_value, list<Employee*>employeeList_value) {
		this->departmentName = departmentName_value;
		this->headOfDepartment = headOfDepartment_value;
		this->employeeList = employeeList_value;
	};

	void setDepartmentName(string departmentName_value) { this->departmentName = departmentName_value; };
	void setHeadOfDepartment(string headOfDepartment_value) { this->headOfDepartment = headOfDepartment_value; };
	string getDepartmentName() { return departmentName; };
	string getHeadOfDepartment() { return headOfDepartment; };

	void printEmployees() {
		for_each(employeeList.begin(), employeeList.end(), printEmployee);
	}
	
	void newEmployee(string position, int BankCardAccount, double salary) {
		Employee* m = new Employee(position, BankCardAccount, salary);
		employeeList.push_back(m);
	}

	friend ostream& operator<< (ostream& os, Department& data)
	{
		os << "Department(DepartmentName = " << data.departmentName << ", Head Of Department = " << data.headOfDepartment << ")"; /*", Employees = " << data.printEmployeeList() << */
		return os;
	}

	~Department() {};
};

