#pragma once
#include"pch.h"

class Person : public HumanEntity
{
protected:
	string number;
	AdressInfo* adr;
	Person() {};
	Person(const Person& obj) { cout << "Person& obj" << endl; };
public:
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
		os << "Person(Number: " << a.number<<")"; //<<*a.adr
		//os << "Adress(City: " << a.adr->getCity << ", Street: " << a.adr->getStreet << ", House Number: " << a.adr->getHouseNumber << ", Apartment Number: " << a.adr->getApartmentNumber << ")";
		return os;
	};

	~Person() {};
};

