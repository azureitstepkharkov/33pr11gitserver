#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>
#include "Person.h"

using namespace std;

class Employee : public Person
{
protected:

	Employee() {};
	string position;
	string bankCard;
	double salary;

private:

	// Constuctor Copy
	Employee(Employee& obj)
	{
		cout << "call Constuctor Copy Employee" << endl;
	}

public:

	Employee(string position, string bankCard, double salary)
	{
		this->position = position;
		this->bankCard = bankCard;
		this->salary = salary;
	}

	// Destructor
	~Employee() {
		cout << "call Destructor Employee" << endl;
	};

	Employee operator = (const Employee & obj) {
		this->sex = obj.sex;
		this->age = obj.age;
		this->firstName = obj.firstName;
		this->lastName = obj.lastName;
		this->phoneNumber = obj.phoneNumber;
		this->address = obj.address;
		this->position = obj.position;
		this->bankCard = obj.bankCard;
		this->salary = obj.salary;
		return *this;
	}
	// прототип перегрузка оператора <<
	friend ostream& operator<< (ostream& os, const Employee& t);
};

// перегрузка оператора <<
ostream& operator<< (ostream& os, const Employee& t)
{
	os << "position  = " << t.position << "bankCard = " << t.bankCard << "salary = " << t.salary;
	return os;
}