#include "stdafx.h"
#include "City.h"

City::City()
{
}

City::City(const City & obj)
{
}

City::~City()
{
	cout << "Destructor city\n";
}

City::City(string cityName)
{
	setCityName(cityName);
}

void City::setCityName(string cityName)
{
	this->cityName = cityName;
}

string City::getCity()
{
	return cityName;
}

ostream & City::operator<<(std::ostream & os)
{

}
