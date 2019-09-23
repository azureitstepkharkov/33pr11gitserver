//Блок 2 Наследование и плиморфизмп
// Задание. Запрограмируйте понятие "Правила расчета ЗП", "Оклад", "Оклад+Премия",
// "Почасовка", "База + % от выручки" 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;

struct ISalaryCalculator
{
	// Виртуальный метод
	virtual double calcSalary() = 0;
};

class Human
{
protected:

	// Default constructor
	Human() 
	{
	
	}
	
	//Constructor copy
	Human(const Human& obj) 
	{
		cout << "call Constructor copy Human" << endl;
	}

public:
	string HumanName;

	Human(string HumanName)
	{ 
		this->HumanName = HumanName;
	}
};

// Правило № 1 для рассчета оклада сотрудника
class Rule1 : public ISalaryCalculator
{
protected:
	double salary;
public:
	Rule1() 
	{ 
		salary = 0;
	}
	Rule1(double salary)
	{ 
		this->salary = salary;
	}

	// Виртуальный метод
	virtual double calcSalary()
	{
		return salary;
	}
};


// Правило № 2 для рассчета оклада + премии сотрудника
class Rule2 : public ISalaryCalculator
{
protected:
	double salary; //
	double premium;

public:
	Rule2() { salary = 0; premium = 0; }
	Rule2(double salary, double premium)
	{
		this->salary = salary; this->premium = premium;
	}
	virtual double calcSalary()
	{
		return salary + premium;
	}
};

//Правило № 3 для рассчета оплаты по часам сотрудника

class Rule3 : public ISalaryCalculator
{
protected:
	double hour; // часы
	double rate; // ставка
public:
	Rule3() 
	{
		hour = 0;
		rate = 0; 
	}

	Rule3(double hour, double rate)
	{
		this->hour = hour; this->rate = rate;
	}

	// Виртуальный метод
	virtual double calcSalary()
	{
		return hour * rate;
	}
};

//Правило № 4 для рассчета  оклад + %от выручки сотрудника

class Rule4 : public ISalaryCalculator
{
protected:

	double salary;
	double percent;
	double proceeds;

public:
	Rule4()
	{ 
		salary = 0;
		percent = 0;
		proceeds = 0;
	}

	Rule4 (double salary, double percent, double proceeds)
	{
		this->salary = salary;
		this->percent = percent;
		this->proceeds = proceeds;
	}
	virtual double calcSalary()
	{
		return salary + percent * proceeds;
	}
};

struct CalcInfo
{
	double hour;
	double revenue;
	double salary;
	double costOfHour;
	double percent;
	double premium; 
};

class Employee : public Human, public ISalaryCalculator
{
protected:
	
	string position;
	double hour;
	double revenue;
	double salary ;
	double costOfHour;
	double percent;
	double premium; 
	 
	ISalaryCalculator* salaryCalc;

	// Default constructor
	Employee() 
	{
		salaryCalc = NULL;
	}

	// Constructor Copy
	Employee(const Employee& obj)
	{
		cout << "call Constructor Copy" << endl;
	}

public:

	// Виртуальный метод
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}
	
	//Destructor
	 ~Employee()
	{
		
	}
	
	Employee(string HumanName, string position, double salary)
		: Human(HumanName)
	{
		this->hour = 0;
		this->position = position;
		this->salary = salary;
		this->percent = 0;
		this->costOfHour = 0;
		this->salaryCalc = new Rule1(salary);
	}
	
	Employee(string HumanName, string position, double salary, double premium)
		:Human(HumanName)
	{
		this->premium = 0;
		this->hour = 0;
		this->position = position;
		this->salary = 0;
		this->percent = 0;
		this->costOfHour = 0;
		this->salaryCalc = new Rule2(this->salary, this->premium);
	}
	
	Employee(string HumanName, string position, double hour, double cost)
		:Human(HumanName)
	{
		this->hour = hour;
		this->position = position;
		this->salary = 0;
		this->costOfHour = cost;
		this->percent = 0;
		this->premium = 0;
		this->salaryCalc = new Rule3(this->hour, this->costOfHour);
	}

	
	Employee(string HumanName, string position, double salary, double revenue, double percent)
		: Human(HumanName)
	{
		this->hour = 0;
		this->position = position;
		this->costOfHour = 0;
		this->salary = salary;
		this->revenue = revenue;
		this->percent = percent;
		this->salaryCalc = new Rule4(salary, percent, revenue);

	}

	Employee(string HumanName, string position, int codePosition, CalcInfo info) : Human(HumanName)

	{
		this->HumanName = HumanName;
		this->position = position;
		this->salary = info.salary;
		this->revenue = info.revenue;
		this->percent = info.percent;
		this->hour = info.hour;
		this->costOfHour = info.costOfHour;

		this->salaryCalc = createSalarycalcRule(codePosition, info);
	}
	static ISalaryCalculator* createSalarycalcRule(int codePosition, CalcInfo info)
	{
		ISalaryCalculator* salaryCalc = NULL;
		switch (codePosition)
		{
		case 1: salaryCalc = new Rule1(info.salary);
			break;
		case 2: salaryCalc = new Rule2(info.salary, info.premium);
			break;
		case 3: salaryCalc = new Rule3(info.hour, info.costOfHour);
			break;
		case 4: salaryCalc = new Rule4(info.salary, info.percent, info.revenue);
			break;
		default: salaryCalc = new Rule1(info.salary);
			break;
		}
		return salaryCalc;
	}
	//перегрузка рператора <<
	friend ostream& operator << (ostream& os, Employee& data)
	{
		os << "name = " << data.HumanName << " position = " << data.position << " salary = " << data.calcSalary() << endl;
		return os;
	}
	
};

	//перегрузка рператора <
	bool operator < (const Employee& c, const Employee& d)
	{
		return c.HumanName < d.HumanName;
	};

	bool moreCompare(Employee* c, Employee* d)
	{
		return c -> calcSalary() < d -> calcSalary();
	};

int main()
{
	setlocale(LC_CTYPE, "rus");
	std::cout << "ExamTask_3\n";

	const int N = 8;
	Employee** employes = new Employee*[N];
	employes[0] = new Employee("Dimidov Alexandr", "Yardman", 180, 7.77 * 20);
	employes[1] = new Employee("Trofimof Oleg", "Programmer", 180, 7.77 * 40);
	employes[2] = new Employee("Ushakova Vera", "General worker", 180, 7.77 * 10);
	employes[3] = new Employee("Pugachev Maxim", "Car Driver", 180, 7.77 * 15);

	CalcInfo info;
	info.premium = 1200;
	info.salary = 1000;
	info.revenue = 500;
	info.percent = 20;
	employes[4] = new Employee("Fedchenko Yaroslav", "Booker", 3, info);
	employes[5] = new Employee("Ugrumova Elena", "Finansist",3, info);
	employes[6] = new Employee("Purtov Andrej", "Boss", 3, info);
	employes[7] = new Employee("Udovichenko Sergej", "Manager", 3, info);

	for (int i = 0; i < N; i++)
	{
		cout << *employes[i] << endl;
	}

	for (int i = 0; i < N; i++) 
	{
		delete employes[i];
	}
	delete[] employes;

	system("pause");
}