#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class HumanEntity : public AnimalEntity
{
protected:
	HumanEntity();
	string name;
	string surname;
public:
	HumanEntity(HumanEntity& obj)
	{
		cout << "call HumanEntity(HumanEntity&)" << endl;
	}

	HumanEntity(string name, string surname)
	{

		this->name = name;
		this->surname = surname;

	}

	~HumanEntity() {
		cout << "call ~HumanEntity()" << endl;
	};

	friend ostream& operator<< (ostream& os, const HumanEntity& t)
	{
		os << "name = "<< t.name<< "surname = "<< t.surname;
		return os;
	}

	void set_name(string name)
	{
		this->name = name;
	}

	void set_surname(string surname)
	{
		this->surname = surname;
	}

	string get_name()
	{
		return this->name;
	}

	string get_surname()
	{
		return this->surname;
	}

};
