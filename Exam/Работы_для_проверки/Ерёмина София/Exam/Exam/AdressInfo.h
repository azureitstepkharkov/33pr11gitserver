#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class AdressInfo : public HumanEntity
{
protected:
	AdressInfo();
	string city;
	string street;
	string houseNumber;
	string officeNumber;
	string apartmentNumber;
public:
	AdressInfo(AdressInfo& obj)
	{
		cout << "call AdressInfo(AdressInfo&)" << endl;
	}
	AdressInfo(string city, string street, string houseNumber, string officeNumber, string apartmentNumber)
	{

		this->city = city;
		this->street = street;
		this->houseNumber = houseNumber;
		this->officeNumber = officeNumber;
		this->apartmentNumber = apartmentNumber;

	}
	
	~AdressInfo() {
		cout << "call ~AdressInfo()" << endl;
	};

	friend ostream& operator<< (ostream& os, const AdressInfo& t)
	{
		os << "city = " << t.city << "street = " << t.street 
		   << "houseNumber = " << t.houseNumber << "houseNumber = " << t.houseNumber
			<< "apartmentNumber = " << t.apartmentNumber;
		return os;
	}

	void set_city(string city)
	{
		this->city = city;
	}

	
	string get_city()
	{
		return this->city;
	}

	void set_street(string street)
	{
		this->street = street;
	}

	string get_street()
	{
		return this->street;
	}


	void set_houseNumber(string houseNumber)
	{
		this->houseNumber = houseNumber;
	}

	string get_houseNumber()
	{
		return this->houseNumber;
	}

	void set_officeNumber(string officeNumber)
	{
		this->officeNumber = officeNumber;
	}

	string get_officeNumber()
	{
		return this->officeNumber;
	}

	void set_apartmentNumber(string apartmentNumber)
	{
		this->apartmentNumber = apartmentNumber;
	}

	string get_apartmentNumber()
	{
		return this->apartmentNumber;
	}


};

