#pragma once
//3 - "База + % от выручки"
#include "ISalaryCalculator.h"
class Rule3 : public ISalaryCalculator
{
protected:
	double base;
	double percent;
	double total;
public:
	Rule3()
	{
		base = 0;
		percent = 0;
		total = 0;
	}
	Rule3(double base, double percent, double bonus)
	{
		this->base = base;
		this->percent = percent;
		this->total = bonus;
	}
	virtual double calcSalary()
	{
		return base + total * percent;
	}
};
