#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "AnimalEntity.h"

using namespace std;

class HumanEntity: public AnimalEntity
{
protected:

	string name;
	string last_name;

	HumanEntity() {}

public:
	HumanEntity(string name, string lname, int age, int sex)
	{
		last_name = lname;
		this->name = name;
		this->age = age;
		this->sex = 1;
	}

	~HumanEntity();
};
