#pragma once
#include"pch.h"

class Person : public HumanEntity
{
protected:
	string number;
	AdressInfo* adr;
	Person() {};
public:
	Person(const Person& obj) { 
		this->number = obj.number;
		this->adr = obj.adr;
	};
	Person(string number_value, AdressInfo* a) {
		this->number = number_value;
		this->adr = a;
	};
	void setNumber(string number_value) { this->number = number_value; };
	void setAdress(AdressInfo* adr_value) { this->adr = adr_value; };
	string getNumber() { return number; };
	AdressInfo* getAdress() { return adr; };


	friend ostream& operator << (ostream& os, Person& a)
	{
		os << "Person(Number: " << a.number << "), " << *a.adr;
		return os;
	};

	~Person() {};
};

