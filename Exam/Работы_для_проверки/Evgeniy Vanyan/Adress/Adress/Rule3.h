#pragma once
#include "IsSalaryCalc.h"
//������� ������� �� ����+%�� �������
class Rule3: public IsSalaryCalc
{
protected:
	double revenue;
	double percent;
	double base;
public:
	Rule3();
	Rule3(double base, double percent,double revenue);
	virtual double calcSalary()
	{
		return this->base + this->revenue * this->percent;
	}
};

