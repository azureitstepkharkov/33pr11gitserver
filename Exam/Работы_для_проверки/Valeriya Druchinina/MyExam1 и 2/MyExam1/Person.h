#pragma once
#include "HumanEntity.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;

//интерфейс
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};

class Person : public HumanEntity
{

protected:

	// конструктор по умолчанию
	Person() {};
	string phone;
	string address;

private:
	//конструктор копирования
	Person(Person& obj)
	{
		cout << "call Person(Person&)" << endl;
	}

public:

	//перегруженный конcтруктор
	Person(string name, string surname, string phone, string address)
	{

		this->phone = phone;
		this->address = address;

	}


	~Person() {
		cout << "call ~Person()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const Person& t)
	{
		os << "phone = "
			<< t.phone
			<< "address = "
			<< t.address;
		return os;
	}

	void print()
	{
		cout << "name = " << this->name << endl;
		cout << "surname = " << this->surname << endl;
		cout << "phone = " << this->phone;
		cout << "address = " << this->address;
	}

	// сеттеры и геттеры
	void set_phone(string phone)
	{
		this->phone = phone;
	}

	void set_address(string address)
	{
		this->address = address;
	}

	string get_phone()
	{
		return this->phone;
	}

	string get_address()
	{
		return this->address;
	}



};

