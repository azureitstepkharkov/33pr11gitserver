#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include"HumanEntity.h"
using namespace std;
class Person : public HumanEntity
{

protected:
	string phone;
	AdressInfo*  adr;
	Person() {};
public:
	Person(string Fname, string Lname) : HumanEntity(Fname, Lname, 18, 1)
	{
		this->phone = "no phone";
	}
	Person(string phone,
		string city,
		string street,
		string houseN,
		string flatN,
		string Fname,
		string Lname,
		int age,
		int sex) : HumanEntity(Fname, Lname, age, sex)
	{

		this->phone = phone;
		this->adr = new AdressInfo(city, street, houseN, flatN);
	}
	Person(string phone, string Fname, string Lname, int age, int sex) : HumanEntity(Fname, Lname, age, sex)
	{
		this->phone = phone;
	}

	void setPhone(string phone)
	{
		this->phone = phone;
	}
	void setAdress(AdressInfo *adr)
	{
		this->adr = adr;
	}

	string getPhone()
	{
		return phone;
	}
	AdressInfo * getAdress()
	{
		return adr;
	}
	friend ostream& operator << (ostream& os, const Person& data)
	{
		os << "First Name: " << data.FirstName
			<< "\n"
			<< "Last Name: " << data.LastName
			<< "\n"
			<< "Age: " << data.age
			<< "\n"
			<< "Sex: " << data.sex
			<< "\n"
			<< "==========Adress information============ "
			<< "\n"
			<< *data.adr << endl;
		return os;
	}

	~Person() {};
};

