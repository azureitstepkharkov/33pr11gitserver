#pragma once
#include <iostream>
#include<string>

using namespace std;
class AdressInfo
{
protected:
	string city;
	string street;
	int houseNumber;
	int apartmentNumber;
	AdressInfo() {};
	AdressInfo(const AdressInfo& obj) { cout << "AdressInfo& obj" << endl; };
public:
	AdressInfo(string city_value, string street_value, int houseNumber_value, int apartmentNumber_value) {
		this->city = city_value;
		this->street = street_value;
		this->houseNumber = houseNumber_value;
		this->apartmentNumber = apartmentNumber_value;
	};
	void setCity(string city_value) { this->city = city_value; };
	void setStreet(string street_value) { this->street = street_value; };
	void setHouseNumber(int houseNumber_value) { this->houseNumber = houseNumber_value; };
	void setApartmentNumber(int apartmentNumber_value) { this->apartmentNumber = apartmentNumber_value; };
	string getCity() { return city; };
	string getStreet() { return street; };
	int getApartmentNumber() { return apartmentNumber; };
	int getHouseNumber() { return houseNumber; };

	friend ostream& operator << (ostream& os, AdressInfo& a)
	{
		os << "Adress(City: " << a.city << ", Street: " << a.street << ", House Number: " << a.houseNumber << ", Apartment Number: " << a.apartmentNumber << ")";
		return os;
	};
	~AdressInfo() {};
};


