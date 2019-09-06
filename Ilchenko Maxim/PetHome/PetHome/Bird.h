#pragma once
#include "Pet.h"
#include <iostream>
class Bird :public Pet
{
public:
	void doEat() { cout << "Zerno"<<endl; }
	void doSound() { cout << "Chirik-Chirik"<<endl; }
	Bird() {};
	~Bird() {};
};