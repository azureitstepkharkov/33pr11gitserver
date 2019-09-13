#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class Person : public AdressInfo
{
protected:
	Person();
	string phone;
	string adress;
public:
	Person(Person& obj)
	{
		cout << "call Person(Person&)" << endl;
	}
	Person(string phone, string adress)
	{

		this->phone = phone;
		this->adress = adress;


	}

	~Person() {
		cout << "call ~Person()" << endl;
	};

	friend ostream& operator<< (ostream& os, const Person& t)
	{
		os << "phone = " << t.phone << "adress = " << t.adress;
		return os;
	}

	void set_phone(string phone)
	{
		this->phone = phone;
	}


	string get_phone()
	{
		return this->phone;
	}

	void set_adress(string adress)
	{
		this->adress = adress;
	}

	string get_adress()
	{
		return this->adress;
	}





};

