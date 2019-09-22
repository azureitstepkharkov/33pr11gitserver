#pragma once
#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include"Employee.h"
using namespace std; 

class Department
{
private:
	string NameOfDep;
	vector< Employee*> collective;
	Employee* boss;
	Department() { };
public:
	Department(string NameOfDep, Employee* boss, vector<Employee*> collective)
	{
		this->NameOfDep = NameOfDep;
		this->boss = boss;
		this->collective = collective;
	}

	

	void AddEmployeeToCollective
	(string Fname, string Lname, string position,
		double base, string cardNum)
	{
		Employee* m = new Employee(Fname, Lname, position, base, cardNum);
		collective.push_back(m);
	}
	friend ostream& operator << (ostream& os, Department& data)
	{
		os << "Department: " << data.NameOfDep
			<< "\n==============================================\n"
			<< "Boss: " << data.boss->getFirstName() << " " << data.boss->getLastName()
			<< "\nWorkers: \n";
		/*
			 for (int i = 0; i < data.collective.size(); i++)
		{
			os << collective[i].FirstName << " "
				<< collective[i].LastName << " "
				<< collective[i].Possition << endl;
		}*/
					

		return os;
	}
	~Department() 
	{
		delete[]boss;
		
	};
};

