#pragma once
#include<string>

using namespace std;

class AdressInfo
{
protected:
	string City;
	string TypeStreet;
	string Street;
	string HouseNumber;
	unsigned int OfficeOrApartmentNum;

	AdressInfo() {};
	AdressInfo(AdressInfo& adress) {};
public:
	AdressInfo(string Ct, string TpStrt, string Strt, string housNm, unsigned int OfAptmNm);
	

	friend ostream& operator<<(ostream& out_data, AdressInfo& adress);
	
	void set_city(string Ct) { this->City = Ct; }
	void set_typestreet(string tpStrt) { this->TypeStreet = tpStrt; }
	void set_street(string strt) { this->Street = strt; }
	void set_housenum(string housnm) { this->HouseNumber = housnm; }
	void set_apartmentnum(unsigned int OfAptNum) { this->OfficeOrApartmentNum = OfAptNum; }

	string get_city() { return this->City; }
	string get_typestreet() { return this->TypeStreet; }
	string get_street() { return this->Street; }
	string get_housenum() { return this->HouseNumber; }
	unsigned int get_apartmentnum() { return this->OfficeOrApartmentNum; }

	~AdressInfo();

};