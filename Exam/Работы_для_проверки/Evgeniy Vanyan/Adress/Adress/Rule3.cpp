#include "pch.h"
#include "Rule3.h"


Rule3::Rule3()
{
	this->base = 0;
	this->percent = 0;
	this->revenue = 0;
}
Rule3::Rule3(double base, double percent,double revenue)
{
	this->base = base;
	this->percent = percent;
	this->revenue = revenue;
}

