#pragma once
//2 - "Оклад + премия"
#include "ISalaryCalculator.h"
class Rule2 : public ISalaryCalculator
{
protected:
	double base;
	double premium;
public:
	Rule2()
	{
		base = 0;
		premium = 0;
	}
	Rule2(double hour, double premium)
	{
		this->base = hour;
		this->premium = premium;
	}
	virtual double calcSalary()
	{
		return base + premium;
	}
};


