#pragma once
#include <iostream>
#include<string>
#include<fstream>

using namespace std;
class AnimalEntity
{
protected:
	int age;
	int sex;
public:
	AnimalEntity() { this->age = 18; this->sex = 1; };
	AnimalEntity(int age, int sex)
	{
		this->age = age;
		this->sex = sex;
	}
	AnimalEntity(const AnimalEntity & obj) {};

	void setAge(int age)
	{
		this->age = age;
	}
	void setSex(int sex)
	{
		this->sex = sex;
	}

	int getAge()
	{
		return age;
	}
	int getSex()
	{
		return sex;
	}

	friend ostream& operator << (ostream& os, const AnimalEntity& data)
	{
		os << "Age: " << data.age
			<< " Sex: " << data.sex << endl;
		return os;
	}

	~AnimalEntity()  {};
};

