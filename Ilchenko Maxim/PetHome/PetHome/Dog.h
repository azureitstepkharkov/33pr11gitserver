#pragma once
#include "Pet.h"
#include <iostream>
class Dog :public Pet
{
public:
	void doEat() { cout << "Meat"; }
	void doSound() { cout << "Gav-gav-gav"; }
	Dog() {};
	~Dog() {};
};
