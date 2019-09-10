#include "stdafx.h"
#include "Street.h"


Street::Street()
{
}


Street::~Street()
{
	cout << "destruct Street\n";
}

Street::Street(string streetName, string Typename) :TypeStreet(Typename)
{
	setStreetName(streetName);
}

void Street::setStreetName(string streetName)
{
	this->streetName = streetName;
}

string Street::getStreetName()
{
	return streetName;
}

Street::Street(const Street & obj)
{
}
