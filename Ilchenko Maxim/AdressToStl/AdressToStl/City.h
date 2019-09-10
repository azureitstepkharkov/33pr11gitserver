#pragma once
#include <iostream>//operator<<
#include<string>//работа со строками
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
