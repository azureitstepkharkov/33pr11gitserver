#pragma once
#include <iostream>//operator<<

#include<string>//работа со строками

#include "TypeStreet.h"
using namespace std;


class Street :public TypeStreet
{
private:
	string streetName;

	Street();
public:

	Street(const Street& obj);
	~Street();
	Street(string streetName, string Typename); 

	void setStreetName(string streetName);

	string getStreetName();
};