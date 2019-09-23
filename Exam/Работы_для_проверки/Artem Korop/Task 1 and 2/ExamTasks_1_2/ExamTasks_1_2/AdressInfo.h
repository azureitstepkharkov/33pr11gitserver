#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;

class AddressInfo
{
protected:
	string city;
	string street;
	int houseNumber;
	int appartNumber;

public:
	AddressInfo()
	{
		this->city = " ";
		this->street = " ";
		this->houseNumber = 0;
		this->appartNumber = 0;
	}

	//Destuctor
	~AddressInfo()
	{
		cout << "call Destuctor AddressInfo()" << endl;
	}
	
	AddressInfo(string city, string street, int houseNumber, int appartNumber)
	{
		this->city = city;
		this->street = street;
		this->houseNumber = houseNumber;
		this->appartNumber = appartNumber;
	}

	
	void setCity(string city)
	{
		this->city = city;
	}
	
	void setStreet(string street)
	{
		this->street = street;
	}
	
	void setHouseNumber(int houseNumber)
	{
		this->houseNumber = houseNumber;
	}
	
	void setAppartNumber(int appartNumber)
	{
		this->appartNumber = appartNumber;
	}
	
	string getCity()
	{
		return this->city;
	}

	string getStreet()
	{
		return this->street;
	}

	int getHouseNumber()
	{
		return this->houseNumber;
	}
	
	int getAppartNumber()
	{
		return this->appartNumber;
	}
	
	void print()
	{
		cout << "Address: " << this->city << ", "
			<< this->street << ", "
			<< this->houseNumber << ", "
			<< this->appartNumber << ";" << endl;
	}

	// прототип перегрузка оператора <<
	friend ostream&	operator << (ostream& os, const AddressInfo& t);
};

ostream& operator << (ostream& os, const AddressInfo& adr)
{
	os << "Address: " << adr.city << ", " << adr.street << ", " << adr.houseNumber << ", " << adr.appartNumber << endl;

	return os;
}