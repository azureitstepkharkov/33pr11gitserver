#include "pch.h"

#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка
using namespace std;
//интерфейс - это struct или class  с секцией public, в которых
//только виртуальные методы
//
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};
//вместо всей иерархии струкутры: Animal->Man->Person
//здесь "заглушка" - только один класс
class Man
{
protected:
	Man(){}
	Man(const Man& onj){}
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
//2 - оплата по часам
class Rule2 : public ISalaryCalculator
{
protected:
	double hour;
	double rate;
public:
	Rule2() { hour = 0; rate = 0; }
	Rule2(double hour, double rate) { this->hour = hour; this->rate = rate; }
	virtual double calcSalary()
	{
		return hour * rate;
	}
};
//3 - оплата с бонусами
class Rule3 : public ISalaryCalculator
{
protected:
	double base;
	double percent;
	double bonus;
public:
	Rule3() { base = 0; percent = 0; bonus = 0; }
	Rule3(double base, double percent, double bonus)
	{
		this->base = base; this->percent = percent; this->bonus = bonus;
	}
	virtual double calcSalary()
	{
		return base + base * percent + bonus;
	}
};
//все данные, которые могут понадобиться для расчета ЗП
struct CalcInfo
{
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или 
	double bonus;//бонус
	double bonus_percent;//процент бонуса
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
};
//можно создать структуру и для всех характеристик...

//пример множественного наследования
class Employee : public Man, public ISalaryCalculator
{
protected:
	//составляющие части зп для расчета:
	double base;//база - оклад
	double percent;//значение %
	double total;//сумма продаж или бонус
	double hour;//количество часов
	double rate_per_hour;//стоимость часа
	//вопрос: а нужно ли их здесь вообще хранить?
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
	/*
	virtual ~Employee()
	{
		if (salaryCalc != NULL)
		{
			delete salaryCalc;
		}
	}
	*/
	//конструктор для должностей с оплатой по правилу 1
	Employee(string name, string position, double base)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->percent = 0;
		this->total = 0;
		this->salaryCalc = new Rule1(base);
	}
	//конструктор для должностей с оплатой по правилу 2
	Employee(string name, string position, double h, double rate)
		:Man(name)
	{
		this->position = position;
		this->hour = h;
		this->rate_per_hour = rate;
		this->percent = 0;
		this->total = 0;
		this->base = 0;
		this->salaryCalc = new Rule2(this->hour, this->rate_per_hour);
	}
	//конструктор для должностей с оплатой по правилу 3
	Employee(string name, string position, double base, double percent,double bonus)
		: Man(name)
	{
		this->position = position;
		this->base = base;
		this->total = bonus;
		this->percent = percent;
		this->hour = 0;
		this->rate_per_hour = 0;
		this->salaryCalc = new Rule3(base, percent, bonus);
	}
	//"универсальный" конструктор
	Employee(string name, string position, int codePosition, CalcInfo info)
		:Man(name)
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
		case 1: salaryCalc = new Rule1(info.base); break;
		case 2: salaryCalc = new Rule2(info.hour, info.rate_per_hour); break;
		case 3: salaryCalc = new Rule3(info.base, info.percent, info.bonus);
			break;
		default: salaryCalc = new Rule1(info.base);
			break;
		}
		return salaryCalc;
	}
	//перегрузка обязательных операторов
	friend ostream& operator<< (ostream& os, Employee& data)
	{
		os << "name = " << data.name << " position = " << data.position
			<< " salary = " << data.calcSalary() << endl;
		return os;
	}
	//
};
//у компилятора хватило "мозгов" понять, что это friend
bool operator< (const Employee& a, const Employee& b)
{
	//return a.calcSalary() < b.calcSalary();
	//стандартная сортировка по умолчанию в stl не умеет работать с виртуальными элементами
	return a.name < b.name;
};
//для того, чтобы задействовать в сортировке виртуальные члены класса
//нужно создавать свою функцию с параметрами УКАЗАТЕЛЯМИ
bool mycomparergreater(Employee* a, Employee* b)
{
	return a->calcSalary() < b->calcSalary();
};
//Задание:
//1 изменить иерархию так, чтобы было видно ФИO, должность, ЗП
//2 ввести правило расчета ЗП для менеджеров продаж
int main()
{
    std::cout << "test Employee:\n";
	/*
	std::cout << "логика указателей:\n";
	const int N = 5;
	Employee** employes = new Employee*[N];
	employes[0] = new Employee("Ivan Petrov", "Accounter", 7500);
	employes[1] = new Employee("Peter Ivanov", "Programmer", 168, 6.25 * 25);
	employes[2] = new Employee("Anna Sidorova", "Senior Cleaner Manager", 80, 35);
	employes[3] = new Employee("BB", "Project Manager", 7500, 25, 10000);
	CalcInfo info;
	info.base = 7500;
	info.percent = 15;
	info.total = 100000;
	employes[4] = new Employee("Alex Alex", "Saler", 4, info);
	//вывод на экран
	for (int i = 0; i < N; i++)
	{
		//cout << employes[i] << endl;// обращение employes[i] вернул Employee*
		cout << *employes[i] << endl;//операция * (разыменование)
		                            //- обращение к содержимому
	}
	//удаление из памяти
	for (int i = 0; i < N; i++)
	{
		delete employes[i];
	}
	delete[] employes;
	*/
	//stl
	//если класс пердполагает использование виртуальных функций
	//то должна использоваться логика указателей.
	//это предотвардит автоматические вызовы деструкторов 
	//особенно до окончания работы конструкторов
	//vector<Employee> MEN(4);//неявный вызов 4 раза конструктора по умолчанию
	vector<Employee*> MEN;
	Employee* m1 = new Employee("tester1", "QA", 500);
	Employee* m2 = new Employee("tester 2", "Junior QA", 300);
	Employee* m3 = new Employee("tester 3", "Junior QA", 400);
	MEN.push_back(m1);//явную перменную
	MEN.push_back(m2);//явную перменную
	MEN.push_back(m3);//явную перменную
	//вывод на экрна до сортировки
	//for_each(MEN.begin(), MEN.end(), printEmployee);//нет перегрузки для работы с Employee*
	vector<Employee*>::iterator ptr;
	// Displaying vector elements using begin() and end() 
	cout << "before sorting : " << endl;;
	for (ptr = MEN.begin(); ptr < MEN.end(); ptr++)
		cout << *(*ptr) << " ";//двойное разыменование
	//sort(MEN.begin(), MEN.end());//по умолчанию оператор <
	//который не может использовать виртуальные члены класса
	sort(MEN.begin(), MEN.end(), mycomparergreater);
	//вывод на экран после сортировки
	cout << "after sorting : "<<endl;
	for (int i = 0; i < MEN.size(); i++)
	{
		cout << *MEN[i] << endl;
		//для списка так не выйде, потому что нет индексатора
		//а для вектора индексатор реализован
	}
	system("pause");
	//Требования к "моему" классу, чтобы класс был "удобным" членом коллекции stl:
	/*
	1. Безопасный конструктор по умолчанию (умеет создавать корректный объект)
	часто protected
	2. Закрытый копирующий конструктор,
	чтобы передавать объект класс только по ссылке или через указатель
	3. оператор вывода <<

	ВАЖНО: только, если не используем полиморфизм
	4. оператор < для версии sort по умолчанию из stl
	5. оператор () для версии sort с шаблонным параметром
	Если используем полиморфизм, то сортировка в версии
	sort(MEN.begin(), MEN.end(), mycomparergreater);
	метод вывода и заполнения - в версии с параметром
	Employee*
	*/
	return 0;
}

