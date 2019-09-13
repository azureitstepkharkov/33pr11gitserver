#include "pch.h"
#include "Person.h"



Person::Person(string phone, AdressInfo * data)
{
	this->phone = phone;
	this->data = data;
}
Person::~Person()
{
}
