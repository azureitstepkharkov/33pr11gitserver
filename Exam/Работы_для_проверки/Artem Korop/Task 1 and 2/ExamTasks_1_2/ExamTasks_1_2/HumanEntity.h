#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>
#include "AnimalEntity.h"

using namespace std;

class HumanEntity : public AnimalEntity
{
protected:

	string firstName;
	string lastName;

private:

	// Constructor Copy
	HumanEntity(HumanEntity& obj)
	{
		cout << "call Constructor Copy HumanEntity" << endl;
	}

public:

	HumanEntity(string firstName, string lastName, bool sex, int age) : AnimalEntity(sex, age)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}
	
	~HumanEntity() {
		cout << "call Distructor HumanEntity" << endl;
	};

	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}

	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	
	string getFirstName()
	{
		return this->firstName;
	}
	
	string getLastName()
	{
		return this->lastName;
	}
	
	void print()
	{
		cout << firstName << " " << lastName << ", sex: " << sex << ", age: " << age << endl;
	}
	
	// прототип перегрузка оператора <<
	friend ostream&	operator << (ostream& os, const HumanEntity& h);
};

//перегрузка оператора <<
ostream& operator << (ostream& os, const HumanEntity& h)
{
	os << h.firstName << " " << h.lastName << ", sex: " << ((h.sex == 0) ? ("male") : ("female"))<< ", age: " << h.age << endl;
	return os;
}