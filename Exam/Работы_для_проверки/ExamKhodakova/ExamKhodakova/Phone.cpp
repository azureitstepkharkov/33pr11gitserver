#include "stdafx.h"
#include "Phone.h"




Phone::Phone(string number, string typePhone)
{
	this->Number = number;
	this->TypePhone = typePhone;
}

Phone::Phone(string number)
{
	this->TypePhone = " ";
	this->Number = number;
}

Phone::~Phone()
{
	
}

ostream & operator<<(ostream & out_data, Phone & phone)
{
	out_data << phone.TypePhone << " : " << phone.Number  << endl;

	return out_data;
}
