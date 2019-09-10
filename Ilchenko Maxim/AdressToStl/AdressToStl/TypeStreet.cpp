#include "stdafx.h"
#include "TypeStreet.h"
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка

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