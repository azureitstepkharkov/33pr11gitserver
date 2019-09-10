#include "stdafx.h"

#include "Adress.h"


Adress::~Adress()
{
	cout << "Destructor Adress\n";
}

Adress::Adress()
{
	cout << NumHouse << endl;
}

Adress::Adress(string namecity, string Typename, string streetName, string NumHouse)
{
	this->city = namecity;
	this->street = streetName;
	this->NumHouse = NumHouse;
	cout << "City " << namecity << endl << "Type street " << Typename << endl << "Street " << streetName << endl
		<< "Num. House " << NumHouse << endl;
}

void Adress::setNumHouse(string NumHouse)
{
	this->NumHouse = NumHouse;
}

string Adress::getNumHouse()
{
	return this->NumHouse;
}

Adress::Adress(const Adress& obj)
{
	this->NumHouse=obj.NumHouse;
}
