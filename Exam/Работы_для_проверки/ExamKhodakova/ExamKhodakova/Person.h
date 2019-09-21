#pragma once
#include<iostream>
#include<string>
#include"HumanEntity.h"
#include"Phone.h"
#include"AdressInfo.h"
using namespace std;

class Person :public HumanEntity
{
protected:
	Phone *phone;
	AdressInfo* adress;

	Person() {};
	Person(Person& per) {};

public:

	
	Person(Phone phone(string number,string type), 
		string City, string TypeStreet, string nameStreet, string housNum, unsigned int ApartmentNum,//личность
			string name, string surname, //человек
				bool sex, unsigned int age);//животное

	friend ostream& operator<<(ostream& out_data, Person& person);
	

	void addPhone(Phone phone);
	~Person() ;
};