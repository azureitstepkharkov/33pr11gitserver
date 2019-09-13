#pragma once
#include "IsSalaryCalc.h"
//������� �1 - ������ �� �����
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

