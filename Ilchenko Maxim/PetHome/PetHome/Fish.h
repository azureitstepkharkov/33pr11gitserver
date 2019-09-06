#pragma once
#include "Pet.h"
#include <iostream>
class Fish :public Pet
{
public:
	void doEat() { cout << "Vodorosli"; }
	void doSound() { cout << "No sound"; }
	Fish() {};
	~Fish() {};
};

