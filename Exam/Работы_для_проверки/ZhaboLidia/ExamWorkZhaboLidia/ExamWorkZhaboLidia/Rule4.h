#pragma once
#include "ISalaryCalculator.h"
// ������� 4 - �����
class Rule4 : public ISalaryCalculator
{
protected:
	double base;
public:
	Rule4() { base = 0; }
	Rule4(double base) { this->base = base; }
	virtual double calcSalary()
	{
		return base;
	}
};