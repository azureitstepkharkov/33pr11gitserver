#pragma once
#include "Person.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;


class Employee : public Person
{
protected:

	// конструктор по умолчанию
	Employee() {};
	string position;
	string bankCard;
	double salary;


private:
	//конструктор копирования
	Employee(Employee& obj)
	{
		cout << "call Employee(Employee&)" << endl;
	}

public:

	//перегруженный конcтруктор
	Employee(string position, string bankCard, double salary)
	{

		this->position = position;
		this->bankCard = bankCard;
		this->salary = salary;

	}


	~Employee() {
		cout << "call ~Employee()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const Employee& t)
	{
		os << "position  = "
			<< t.position
			<< "bankCard = "
			<< t.bankCard
			<< "salary = "
			<< t.salary;
		return os;
	}


};

