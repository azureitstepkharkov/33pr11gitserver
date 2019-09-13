#pragma once
#include "AnimalEntity.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;


class HumanEntity : public AnimalEntity
{
protected:

	// конструктор по умолчанию
	HumanEntity() {};
	string name;
	string surname;

private:
	//конструктор копирования
	HumanEntity(HumanEntity& obj)
	{
		cout << "call HumanEntity(HumanEntity&)" << endl;
	}

public:

	//перегруженный конcтруктор
	HumanEntity(string name, string surname)
	{

		this->name = name;
		this->surname = surname;

	}


	~HumanEntity() {
		cout << "call ~HumanEntity()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const HumanEntity& t)
	{
		os << "name = "
			<< t.name
			<< "surname = "
			<< t.surname;
		return os;
	}

	//// сеттеры и геттеры
	//void set_name(string name)
	//{
	//	this->name = name;
	//}

	//void set_surname(string surname)
	//{
	//	this->surname = surname;
	//}

	//string get_name()
	//{
	//	return this->name;
	//}

	//string get_surname()
	//{
	//	return this->surname;
	//}


};

