#include "stdafx.h"
#include "AdressInfo.h"




AdressInfo::~AdressInfo()
{
}

AdressInfo::AdressInfo(string Ct, string TpStrt, string Strt, string housNm, unsigned int OfAptmNm)
{
	this->City = Ct;
	this->TypeStreet = TpStrt;
	this->Street = Strt;
	this->HouseNumber = housNm;
	this->OfficeOrApartmentNum = OfAptmNm;
}

ostream & operator<<(ostream & out_data, AdressInfo & adress)
{
	out_data <<"����� "<< adress.City << ", " << adress.TypeStreet << " " << adress.Street
		<< "  ��� " << adress.HouseNumber << ", " << adress.OfficeOrApartmentNum << endl;
	return out_data;
}