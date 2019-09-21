#include "pch.h"
#include <iostream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;

//интерфейс
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};

class Man
{
protected:
	Man() {}
	Man(const Man& onj) {}
public:
	string name;//закрыть!
	//метода setName - не должно быть
	//string getName
	Man(string name) { this->name = name; }
};



//классы, которые хранят правила для рассчетов
//1 - оклад
class Rule1 : public ISalaryCalculator
{
protected:
	double base;
public:
	Rule1() { base = 0; }
	Rule1(double base) { this->base = base; }
	virtual double calcSalary()
	{
		return base;
	}
};


//2 - оклад + премия
class Rule2 : public ISalaryCalculator
{
protected:
	double base;
	double premium;

public:
	Rule2() { base = 0; premium = 0; }
	Rule2(double base, double premium)
	{
		this->base = base; this->premium = premium;
	}
	virtual double calcSalary()
	{
		return base + premium;
	}
};

//3 - оплата по часам
class Rule3 : public ISalaryCalculator
{
protected:
	double hour;
	double rate;
public:
	Rule3() { hour = 0; rate = 0; }
	Rule3(double hour, double rate)
	{
		this->hour = hour; this->rate = rate;
	}
	virtual double calcSalary()
	{
		return hour * rate;
	}
};

//4 - оклад + %от выручки
class Rule4 : public ISalaryCalculator
{
protected:
	double base;
	double percent;
	double proceeds;
public:
	Rule4() { base = 0; percent = 0; proceeds = 0; }
	Rule4(double base, double percent, double proceeds)
	{
		this->base = base;
		this->percent = percent;
		this->proceeds = proceeds;
	}
	virtual double calcSalary()
	{
		return base + percent * proceeds;
	}
};


//все данные, которые могут понадобиться для расчета ЗП
struct CalcInfo
{
	double base;//база - оклад
	double percent;//значение %
	double proceeds;//сумма выручки
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
	double premium; // премия


};


//пример множественного наследования
class Employee : public Man, public ISalaryCalculator
{
protected:
	//составляющие части зп для расчета:
	double base;//база - оклад
	double percent;//значение %
	double proceeds;//сумма выручки
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
	double premium; // премия


	string position;//название должности

	ISalaryCalculator* salaryCalc;//механизм расчета ЗП

	//конструктор по умолчанию
	Employee() { salaryCalc = NULL; }

	//копирующий конструктор по умолчанию
	Employee(const Employee& obj) {}

public:
	//
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}
	
	//конструктор для должностей с оплатой по правилу 1
	Employee(string name, string position, double base)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->percent = 0;

		this->salaryCalc = new Rule1(base);
	}
	//конструктор для должностей с оплатой по правилу 2
	Employee(string name, string position, double base, double premium)
		:Man(name)
	{
		this->position = position;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->percent = 0;
		this->base = 0;
		this->premium = 0;
		this->salaryCalc = new Rule2(this->base, this->premium);
	}
	//конструктор для должностей с оплатой по правилу 3
	/*Employee(string name, string position, double h, double rate)
		:Man(name)
	{
		this->position = position;
		this->hour = h;
		this->rate_per_hour = rate;
		this->percent = 0;
		this->premium = 0;
		this->base = 0;
		this->salaryCalc = new Rule3(this->hour, this->rate_per_hour);
	}*/

	//конструктор для должностей с оплатой по правилу 4
	Employee(string name, string position, double base, double proceeds, double percent)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->proceeds = proceeds;
		this->percent = percent;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->salaryCalc = new Rule4(base, percent, proceeds);

	}

	
	Employee(string name, string position, int codePosition, CalcInfo info) : Man(name)

	{
		this->name = name;
		this->position = position;
		this->base = info.base;
		this->proceeds = info.proceeds;
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
		case 1: salaryCalc = new Rule1(info.base);
			break;
		case 2: salaryCalc = new Rule2(info.base, info.premium);
			break;
		case 3: salaryCalc = new Rule3(info.hour, info.rate_per_hour);
			break;
		case 4: salaryCalc = new Rule4(info.base, info.percent, info.proceeds);
			break;
		default: salaryCalc = new Rule1(info.base);
			break;
		}
		return salaryCalc;
	}

	friend ostream& operator<< (ostream& os, Employee& data)
	{
		os << "name = " << data.name << " position = " << data.position
			<< " salary = " << data.calcSalary() << endl;
		return os;
	}
	
};

bool operator< (const Employee& a, const Employee& b)
{
	return a.name < b.name;
};

bool mycomparergreater(Employee* a, Employee* b)
{
	return a->calcSalary() < b->calcSalary();
};

int main()
{
	setlocale(0, "");

	std::cout << "Вывод :\n";

	vector<Employee*> MEN;
	Employee* m1 = new Employee("Ivan Petrov", "janitor", 500);
	Employee* m2 = new Employee("Peter Ivanov", "Programmer", 300);
	Employee* m3 = new Employee("Anna Sidorova", "handyman", 400);
	MEN.push_back(m1);
	MEN.push_back(m2);
	MEN.push_back(m3);
	vector<Employee*>::iterator ptr;
	cout << "До сортировки : " << endl;
	for (ptr = MEN.begin(); ptr < MEN.end(); ptr++)
		cout << *(*ptr) << " ";
	sort(MEN.begin(), MEN.end(), mycomparergreater);

	cout << endl;
	cout << "После сортировки : " << endl;
	for (int i = 0; i < MEN.size(); i++)
	{
		cout << *MEN[i] << endl;
	}
	system("pause");

	