#include "stdafx.h"

#include "AdressInfo.h"


AdressInfo::~AdressInfo()
{
	cout << "Destructor\n";
}

AdressInfo::AdressInfo()
{
	cout << NumApartment << endl;
}

AdressInfo::AdressInfo(string namecity, string Typename, string streetName, string NumApartment)
{
	this->city = namecity;
	this->street = streetName;
	this->NumApartment = NumApartment;
	cout << "City " << namecity << endl << "Type street " << Typename << endl << "Street " << streetName << endl
		<< "Num. House " << NumApartment << endl;
}

void AdressInfo::setNumApartment(string NumApartment)
{
	this->NumApartment = NumApartment;
}

string AdressInfo::getNumApartment()
{
	return this->NumApartment;
}

AdressInfo::AdressInfo(const AdressInfo& obj)
{
	this->NumApartment =obj.NumApartment;
}
