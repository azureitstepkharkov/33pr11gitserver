#pragma once
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;



class Department
{
protected:

	// конструктор по умолчанию
	Department() {};
	string NameDepartment;
	string EmployeesList;
	string HeadOfDepartment;


private:
	//конструктор копирования
	Department(Department& obj)
	{
		cout << "call Department(Department&)" << endl;
	}

public:

	//перегруженный конcтруктор
	Department(string NameDepartment, string EmployeesList, string HeadOfDepartment)
	{

		this->NameDepartment = NameDepartment;
		this->EmployeesList = EmployeesList;
		this->HeadOfDepartment = HeadOfDepartment;
		

	}


	~Department() {
		cout << "call ~Department()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const Department& t)
	{
		os << "NameDepartment   = "
			<< t.NameDepartment
			<< "EmployeesList = "
			<< t.EmployeesList
			<< "HeadOfDepartment = "
			<< t.HeadOfDepartment;
		return os;
	}


	// сеттеры и геттеры
	void set_NameDepartment(string NameDepartment)
	{
		this->NameDepartment = NameDepartment;
	}
	string get_NameDepartment()
	{
		return this->NameDepartment;
	}


};

