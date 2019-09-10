#pragma once
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;
class Pet :public Animal
{
protected:
	string Nick;
public:
	string getNick() { return Nick; }
	void setNick(string nick) { Nick = nick; }
	Pet(string n) { Nick = n; }
	Pet() { Nick = "no nick"; };
	~Pet() {};
};

