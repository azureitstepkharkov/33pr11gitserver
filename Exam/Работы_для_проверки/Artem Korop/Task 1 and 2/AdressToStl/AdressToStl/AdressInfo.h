#pragma once
#include <iostream>
#include "City.h"
#include "TypeStreet.h"
#include "Street.h"
#include <string>

using namespace std;

class AdressInfo
{
private:
	City  city;
	Street street;
	string NumApartment;

	AdressInfo();
public:
	
	AdressInfo(string namecity, string Typename, string streetName, string NumApartment);
	AdressInfo(const AdressInfo& obj);
	~AdressInfo();
	
	void setNumApartment(string NumApartment);

	string getNumApartment();
};