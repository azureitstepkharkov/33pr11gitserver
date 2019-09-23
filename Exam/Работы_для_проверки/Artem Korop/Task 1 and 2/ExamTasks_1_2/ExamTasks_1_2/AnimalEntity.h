#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;

class AnimalEntity
{
protected:
	bool sex;
	int age;

private:

	AnimalEntity(AnimalEntity& obj)
	{
		cout << "call Constructor Copy AnimalEntity" << endl;
	}

public:

	AnimalEntity(int age, bool sex)
	{
		this->age = age;
		this->sex = sex;
	}
	
	// Destuctor
	~AnimalEntity()
	{
		cout << "call Destructor AnimalEntity()" << endl;
	}
	
	// геттер
	bool getSex()
	{
		return this->sex;
	}
	
	// геттер
	int getAge()
	{
		return this->age;
	}

	// сеттер
	void setSex(bool sex)
	{
		this->sex = sex;
	}

	// сеттер
	void setAge(int age)
	{
		this->age = age;
	}
	
	// вывод в консоль
	void print()
	{
		cout << this->sex << ", " << this->age << ";" << endl;
	}
	
	// прототип перегрузка оператора <<
	friend ostream&	operator << (ostream& os, const AnimalEntity& c);
};

//перегрузка оператора <<
ostream& operator<<(ostream& os, const AnimalEntity& animal)
{
	os << animal.sex << ", " << animal.age << endl;

	return os;
}