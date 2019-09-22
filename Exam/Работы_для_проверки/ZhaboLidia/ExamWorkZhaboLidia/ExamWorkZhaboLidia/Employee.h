#pragma once
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка
#include "ISalaryCalculator.h"
#include  "Person.h"
#include "CalcInfo.h"
#include"Rule1.h"
#include"Rule2.h"
#include "Rule3.h"
#include "Rule4.h"
using namespace std;
class Employee : public Person, public ISalaryCalculator
{
protected:
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или бонус
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
	//------------------------------------
	string position;
	string cardNum;
	ISalaryCalculator* salaryCalc;
	
	
public:
    Employee(const Employee & obj) {};
	Employee() { salaryCalc = NULL; };
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}

	string getPossition()
	{
		return position;
	}
	//конструктор для должностей с оплатой по правилу 1
	Employee(string Fname, string Lname, string position,
		double h, double rate, string cardNum)
		:Person(Fname, Lname)
	{
		this->cardNum = cardNum;
		this->position = position;
		this->hour = h;
		this->rate_per_hour = rate;
		this->percent = 0;
		this->total = 0;
		this->base = 0;
		this->salaryCalc = new Rule1(this->hour, this->rate_per_hour);
	}
	//конструктор для должностей с оплатой по правилу 2
	Employee(string Fname, string Lname, string position,
		double base, double percent, double total)
		:Person(Fname, Lname)
	{
		this->cardNum = cardNum;
		this->position = position;
		this->base = base;
		this->total = 0;
		this->percent = percent;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->salaryCalc = new Rule2(base, percent);
	}
	//конструктор для должностей с оплатой по правилу 3
	Employee(string Fname, string Lname, double total,
		double base, double percent, string position)
		:Person(Fname, Lname)
	{
		this->cardNum = cardNum;
		this->position = position;
		this->base = base;
		this->total = total;
		this->percent = percent;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->salaryCalc = new Rule3(base, percent, total);
	}
	//конструктор для должностей  по правилу 4
	Employee(string Fname, string Lname, string position,
		double base, string cardNum)
		:Person(Fname, Lname)
	{
		this->cardNum = cardNum;
		this->position = position;
		this->base = base;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->percent = 0;
		this->total = 0;
		this->salaryCalc = new Rule4(base);
	}


	// универсальный конструктор 
	Employee(string Fname, string Lname, string position, int codePosition, CalcInfo info)
		:Person(Fname, Lname)
	{
		this->position = position;
		this->base = info.base;
		this->total = info.bonus;
		this->percent = info.percent;
		this->hour = info.hour;
		this->rate_per_hour = info.rate_per_hour;
		this->salaryCalc = createSalarycalcRule(codePosition, info);
	}
	static ISalaryCalculator* createSalarycalcRule(int codePosition, CalcInfo info)
	{
		ISalaryCalculator* salaryCalc = NULL;
		switch (codePosition)
		{
		case 1: salaryCalc = new Rule1(info.hour, info.rate_per_hour); break;
		case 2: salaryCalc = new Rule2(info.base, info.bonus); break;
		case 3: salaryCalc = new Rule3(info.base, info.percent, info.bonus); break;
		case 4: salaryCalc = new Rule4(info.base); break;

		default: salaryCalc = new Rule4(info.base);
			break;
		}
		return salaryCalc;
	}
	//================================================

	friend bool operator< (const Employee& a, const Employee& b)
	{
		//return a.calcSalary() < b.calcSalary();
		return a.FirstName < b.FirstName;
	};
	bool mycomparergreater(Employee* a, Employee* b)
	{
		return a->calcSalary() < b->calcSalary();
	};

	friend ostream& operator << (ostream& os, Employee& data)
	{
		os << "Name: " << data.FirstName << " " << data.LastName
			<< "\n"
			<< "Position: " << data.position
			<< "\n"
			<< "Number of credit card: " << data.cardNum
			<< "\n"
			<< "Salary: " << data.calcSalary() << endl;
		return os;
	}

	void PrintEmployee(Employee& elem)
	{
		cout << elem.FirstName << ' ' << elem.LastName << endl;
	};
	~Employee() {};
};

