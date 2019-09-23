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

class Person : public HumanEntity
{

protected:

	string phoneNumber;
	string address;

	Person() {

	};

private:

	//Constructor Copy
	Person(Person& obj)
	{
		cout << "call Constructor Copy Person" << endl;
	}

public:

	Person(string firstName, string lastName, string phoneNumber, string address)
	{

		this->phoneNumber = phoneNumber;
		this->address = address;

	}

	// Distructor
	~Person() {
		cout << "call Distructor Person" << endl;
	};

	void setPhone(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}

	void setAddress(string address)
	{
		this->address = address;
	}

	string getPhone()
	{
		return this->phoneNumber;
	}

	string getAddress()
	{
		return this->address;
	}

	void print()
	{
		cout << "name = " << this->firstName << endl;
		cout << "surname = " << this->lastName << endl;
		cout << "phoneNumber = " << this->phoneNumber;
		cout << "address = " << this->address;
	}

	// прототип перегрузка оператора <<
	friend ostream& operator<< (ostream& os, const Person& p);
};

//перегрузка оператора <<
ostream& operator<< (ostream& os, const Person& p)
{
	os << "phoneNumber = " << p.phoneNumber << "address = " << p.address;
	return os;
}