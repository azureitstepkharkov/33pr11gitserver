#pragma once
#include "IsSalaryCalc.h"
//правила расчета по окладу
class Rule4 : public IsSalaryCalc
{
protected:
	double base;
public:
	Rule4();
	Rule4(double base);
	virtual double calcSalary()
	{
		return base;
	}
	
};

