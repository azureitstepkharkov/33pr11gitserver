#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "AnimalEntity.h"

using namespace std;

class Person : public AnimalEntity
{
protected:

	string phone;
	string adress;

public:
	
	Person() { cout << "call Person()" << endl; }
	~Person()
	{
		cout << "call ~Person()" << endl;
	}
	
	Person(string name, string lname, int age, int sex, string phone, string adress)
	{
		AnimalEntity(name, lname, age, sex);
		this->phone = phone;
		this->adress = adress;
	}

	friend ostream&	operator<< (ostream& os, const Person& t)
	{
		os << "name = " << t.name << " age = " << t.age << " phone" << t.phone << " adress" << t.adress << endl;
		return os;
	}
	
	void print()
	{
		cout << "name = " << this->name << endl;
		cout << "last name = " << this->last_name << endl;
		cout << "age = " << this->age;
	}

};