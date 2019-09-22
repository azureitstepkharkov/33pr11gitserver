#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include"AnimalEntity.h"
#include "AdressInfo.h"
using namespace std;

class HumanEntity : public AnimalEntity
{
protected:
	string FirstName;
	string LastName;
	HumanEntity() {};
public:
	HumanEntity(string FirstName,
				string LastName,
				int age, 
				int sex): AnimalEntity(age, sex)
	{
		this-> FirstName = FirstName;
		this->LastName = LastName;
	}
	void setFirstName(string FirstName)
	{
		this->FirstName = FirstName;
	}
	void setLastName(string LastName)
	{
		this->LastName = LastName;
	}

	string getFirstName()
	{
		return FirstName;
	}
	string getLastName()
	{
		return LastName;
	}


	friend ostream& operator << (ostream& os,  HumanEntity& data)
	{
		os << "First Name: " << data.FirstName
			<< "\n"
			<< " Last Name: " << data.LastName
			<< "\n"
			<< " Age: " << data.age
			<< "\n"
			<< " Sex: " << data.sex << endl;
		return os;
	} 
	
	~HumanEntity() {};
};

