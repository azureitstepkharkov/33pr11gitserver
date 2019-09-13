#pragma once
#include <iostream>
#include <string>

using namespace std;

class City
{
private:
	string cityName;
	City();

public:
	
	City(const City& obj);
	~City();
	City(string cityName);
	
	void setCityName(string cityName);
	string getCity();

	ostream& operator<<(std::ostream& os);
};
