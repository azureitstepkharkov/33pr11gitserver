#pragma once

class SalaryCalc
{
public:
	SalaryCalc() {};

	virtual double calcSalary() = 0;

	~SalaryCalc() {};
};