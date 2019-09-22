// В этом файле содержится проекта SalaryCalcTester

#pragma once
#include "Libraries.h"
#include "Employee.h"

// Интерфейс - это struct или class с секцией public, в которых только виртуальные методы
class ISalaryCalculator {
public:
	// Виртуальный метод подсчета ЗП
	virtual double getSalary() = 0;
	// Чистый виртуальный деструктор
	virtual ~ISalaryCalculator() = 0 {};
};

// Классы, которые хранят правила для рассчетов

// 1 - оклад
class Rule1 : public ISalaryCalculator {
protected:
	double base;
public:
	Rule1() { base = 0; }
	Rule1(double base) { this->base = base; }
	// Переопределенный метод подсчета ЗП для Rule1
	double getSalary() override {
		return base;
	}
	~Rule1() {};
};
// 2 - оклад и премия
class Rule2 : public ISalaryCalculator {
protected:
	double base;
	double bonus;
public:
	Rule2() { base = 0; bonus = 0; }
	Rule2(double base, double bonus) {
		this->base = base; this->bonus = bonus;
	}
	// Переопределенный метод подсчета ЗП для Rule2
	double getSalary() override {
		return base + bonus;
	}
	~Rule2() {};
};
// 3 - оплата по часам
class Rule3 : public ISalaryCalculator {
protected:
	double hour;
	double ratePerHour;
public:
	Rule3() { hour = 0; ratePerHour = 0; }
	Rule3(double hour, double ratePerHour) { 
		this->hour = hour; this->ratePerHour = ratePerHour;
	}
	// Переопределенный метод подсчета ЗП для Rule3
	double getSalary() override {
		return hour * ratePerHour;
	}
	~Rule3() {};
};
// 4 - оплата с % от выручки
class Rule4 : public ISalaryCalculator {
protected:
	double base;
	double percent;
	double earnings;
public:
	Rule4() { base = 0; percent = 0; earnings = 0; }
	Rule4(double base, double percent, double earnings) {
		this->base = base; this->percent = percent; this->earnings = earnings;
	}
	// Переопределенный метод подсчета ЗП для Rule4
	double getSalary() override {
		return base + (earnings * percent);
	}
	~Rule4() {};
};