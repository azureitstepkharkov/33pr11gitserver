#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

class AnimalEntity
{
protected:

	int age;
	int sex;

public:

	AnimalEntity() {
		age = 18;
		sex = 1;
	};
	~AnimalEntity();
};
