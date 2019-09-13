#pragma once

#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;


class AnimalEntity
{

protected:

	// конструктор по умолчанию
	AnimalEntity()
	{
	};
	int age;
	int sex;

private:
	//конструктор копирования
	AnimalEntity(AnimalEntity& obj)
	{
		cout << "call AnimalEntity(AnimalEntity&)" << endl;
	}

public:

	//перегруженный конcтруктор
	AnimalEntity(int age, int sex)
	{

		this->age = age;
		this->sex = sex;

	}


	~AnimalEntity() {
		cout << "call ~AnimalEntity()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const AnimalEntity& t)
	{
		os << "age = "
			<< t.age
			<< "sex = "
			<< t.sex;
		return os;
	}

	// сеттеры и геттеры
	void set_sex(int sex) 
	{ 
		this->sex = sex; 
	}

	void set_age(unsigned int age) 
	{ 
		this->age = age; 
	}

	int get_sex() 
	{ 
		return this->sex; 
	}

	unsigned int get_age() 
	{ 
		return this->age; 
	}

};

