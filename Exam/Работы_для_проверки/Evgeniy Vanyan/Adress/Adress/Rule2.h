#pragma once
#include "IsSalaryCalc.h"
//������� �2 ����� + ������
class Rule2 : public IsSalaryCalc
{
protected:
	double base;
	double premium;
public:
	Rule2();
	Rule2(double base, double premium);
	virtual double calcSalary()
	{
		return this->base + this->premium;
	}
	
};

