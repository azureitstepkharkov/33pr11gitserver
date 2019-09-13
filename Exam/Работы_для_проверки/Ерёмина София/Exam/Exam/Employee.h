#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class Employee
{
protected:
	Employee();
	string position;
	string score;
	string salary;
public:
	Employee(Employee& obj)
	{
		cout << "call Employee(Employee&)" << endl;
	}
	Employee(string position, string score, string salary)
	{

		this->position = position;
		this->score = score;
		this->salary = salary;

	}

	~Employee() {
		cout << "call ~Employee()" << endl;
	};

	friend ostream& operator<< (ostream& os, const Employee& t)
	{
		os << "departmentName = " << t.departmentName << "listEmployees = " << t.listEmployees << "headDepartment = " << t.headDepartment;
		return os;
	}

	void set_position(string position)
	{
		this->position = position;
	}


	string get_position()
	{
		return this->position;
	}

	void set_score(string score)
	{
		this->score = score;
	}

	string get_score()
	{
		return this->score;
	}

	void set_salary(string salary)
	{
		this->salary = salary;
	}

	string get_salary()
	{
		return this->salary;
	}

};

