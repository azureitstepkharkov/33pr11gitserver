#pragma once
#include"pch.h"

class AnimalEntity : public AdressInfo
{
protected:
	string sex;
	int age;
	AnimalEntity() {};
	AnimalEntity(const AnimalEntity& obj) { cout << "AnimalEntity& obj" << endl; };
public:
	AnimalEntity(string sex_value, int age_value) {
		this->sex = sex_value;
		this->age = age_value;
	};
	void setSex(string sex_value) { this->sex = sex_value; };
	void setAge(int age_value) { this->age = age_value; };
	string getSex() { return sex; };
	int getAge() { return age; };

	friend ostream& operator << (ostream& os, AnimalEntity& a)
	{
		os << "AnimalEntityInfo(Sex: " << a.sex << ", Age: " << a.age << ")";
		return os;
	};

	~AnimalEntity() {};
};

