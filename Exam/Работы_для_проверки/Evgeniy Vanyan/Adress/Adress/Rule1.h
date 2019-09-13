#pragma once
#include "IsSalaryCalc.h"
//Правило №1 - оплата по часам
class Rule1 : public IsSalaryCalc
{
protected:
	double hours;
	double rate;
public:
	Rule1();
	Rule1(double hours, double rate);
	virtual double calcSalary()
	{
		return this->hours * this->rate;
	}
	~Rule1();
};

