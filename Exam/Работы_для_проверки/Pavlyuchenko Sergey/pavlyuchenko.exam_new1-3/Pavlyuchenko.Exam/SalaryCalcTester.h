// � ���� ����� ���������� ������� SalaryCalcTester

#pragma once
#include "Libraries.h"
#include "Employee.h"

// ��������� - ��� struct ��� class � ������� public, � ������� ������ ����������� ������
class ISalaryCalculator {
public:
	// ����������� ����� �������� ��
	virtual double getSalary() = 0;
	// ������ ����������� ����������
	virtual ~ISalaryCalculator() = 0 {};
};

// ������, ������� ������ ������� ��� ���������

// 1 - �����
class Rule1 : public ISalaryCalculator {
protected:
	double base;
public:
	Rule1() { base = 0; }
	Rule1(double base) { this->base = base; }
	// ���������������� ����� �������� �� ��� Rule1
	double getSalary() override {
		return base;
	}
	~Rule1() {};
};
// 2 - ����� � ������
class Rule2 : public ISalaryCalculator {
protected:
	double base;
	double bonus;
public:
	Rule2() { base = 0; bonus = 0; }
	Rule2(double base, double bonus) {
		this->base = base; this->bonus = bonus;
	}
	// ���������������� ����� �������� �� ��� Rule2
	double getSalary() override {
		return base + bonus;
	}
	~Rule2() {};
};
// 3 - ������ �� �����
class Rule3 : public ISalaryCalculator {
protected:
	double hour;
	double ratePerHour;
public:
	Rule3() { hour = 0; ratePerHour = 0; }
	Rule3(double hour, double ratePerHour) { 
		this->hour = hour; this->ratePerHour = ratePerHour;
	}
	// ���������������� ����� �������� �� ��� Rule3
	double getSalary() override {
		return hour * ratePerHour;
	}
	~Rule3() {};
};
// 4 - ������ � % �� �������
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
	// ���������������� ����� �������� �� ��� Rule4
	double getSalary() override {
		return base + (earnings * percent);
	}
	~Rule4() {};
};