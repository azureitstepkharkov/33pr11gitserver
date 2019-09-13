#pragma once
#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class AnimalEntity
{
protected:
	AnimalEntity();
	int age;
	int sex;
public:
	AnimalEntity(AnimalEntity& obj)
	{
		cout << "call AnimalEntity(AnimalEntity&)" << endl;
	}
	AnimalEntity(int age, int sex)
	{

		this->age = age;
		this->sex = sex;


	}

	~AnimalEntity() {
		cout << "call ~AnimalEntity()" << endl;
	};

	friend ostream& operator<< (ostream& os, const AnimalEntity& t)
	{
		os << "age = " << t.age << "sex = " << t.sex;
		return os;
	}

	void set_age(int age)
	{
		this->age = age;
	}


	int get_age()
	{
		return this->age;
	}

	void set_sex(int adresexss)
	{
		this->sex = sex;
	}

	int get_sex()
	{
		return this->sex;
	}





};

