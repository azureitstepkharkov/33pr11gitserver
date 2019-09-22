#pragma once
#include "Header.h"

class Rule1 : public SalaryCalc
{
protected:
	double hour;
	double rate;
public:
	Rule1()	{
		hour = 0;
		rate = 0;
	}

	Rule1(double hour, double rate) {
		this->hour = hour;
		this->rate = rate;
	}

	virtual double calcSalary() {
		return hour * rate;
	}
};