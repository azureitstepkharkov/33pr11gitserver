#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class Department
{
protected:
	Department();
	string departmentName;
	string listEmployees;
	string headDepartment;
public:
	Department(Department& obj)
	{
		cout << "call Department(Department&)" << endl;
	}
	Department(string departmentName, string listEmployees, string headDepartment)
	{

		this->departmentName = departmentName;
		this->listEmployees = listEmployees;
		this->headDepartment = headDepartment;

	}

	~Department() {
		cout << "call ~Department()" << endl;
	};

	friend ostream& operator<< (ostream& os, const Department& t)
	{
		os << "departmentName = " << t.departmentName << "listEmployees = " << t.listEmployees << "headDepartment = " << t.headDepartment;
		return os;
	}

	void set_departmentName(string departmentName)
	{
		this->departmentName = departmentName;
	}


	string get_departmentName()
	{
		return this->departmentName;
	}

	void set_listEmployees(string listEmployees)
	{
		this->listEmployees = listEmployees;
	}

	string get_listEmployees()
	{
		return this->listEmployees;
	}

	void set_headDepartment(string headDepartment)
	{
		this->headDepartment = headDepartment;
	}

	string get_headDepartment()
	{
		return this->headDepartment;
	}

};

