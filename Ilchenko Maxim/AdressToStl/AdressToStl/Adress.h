#pragma once
#include <iostream>//operator<<
#include "City.h"
#include "TypeStreet.h"
#include "Street.h"
#include<string>//работа со строками

using namespace std;
class Adress
{
private:
	City  city;
	Street street;
	string NumHouse;

	Adress();
public:
	
	Adress(string namecity, string Typename, string streetName, string NumHouse);
	Adress(const Adress& obj);
	~Adress(); 
	
	
	void setNumHouse(string NumHouse);

	string getNumHouse();
};