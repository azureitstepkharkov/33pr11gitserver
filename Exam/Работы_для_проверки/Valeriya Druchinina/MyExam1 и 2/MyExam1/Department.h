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

	// ����������� �� ���������
	Department() {};
	string NameDepartment;
	string EmployeesList;
	string HeadOfDepartment;


private:
	//����������� �����������
	Department(Department& obj)
	{
		cout << "call Department(Department&)" << endl;
	}

public:

	//������������� ���c�������
	Department(string NameDepartment, string EmployeesList, string HeadOfDepartment)
	{

		this->NameDepartment = NameDepartment;
		this->EmployeesList = EmployeesList;
		this->HeadOfDepartment = HeadOfDepartment;
		

	}


	~Department() {
		cout << "call ~Department()" << endl;
	};

	//���������� ��������� <<
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


	// ������� � �������
	void set_NameDepartment(string NameDepartment)
	{
		this->NameDepartment = NameDepartment;
	}
	string get_NameDepartment()
	{
		return this->NameDepartment;
	}


};

