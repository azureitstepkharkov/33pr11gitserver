#include "stdafx.h"
#include "TypeStreet.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;

TypeStreet::TypeStreet()
{
}

TypeStreet::~TypeStreet()
{
	cout << "Delete TypeStreet\n";
}
TypeStreet::TypeStreet(const TypeStreet & obj)
{
}

TypeStreet::TypeStreet(string Typename)
{
	setTypeStreetName(Typename);
}

void TypeStreet::setTypeStreetName(string Typename)
{
	this->Typename = Typename;
}

string TypeStreet::getTypeStreetName()
{
	return Typename;
}