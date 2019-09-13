#pragma once
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "AnimalEntity.h"
#include <string>
using namespace std;
class Person : protected AdressInfo, HumanEntity, AnimalEntity
{
private:
	//Person() {};
	Person(const Person& obj) {};
protected:

	string phone;
	AdressInfo *data;
public:
	Person() {};
	Person(string phone, AdressInfo * data);
	friend ostream& operator<<(ostream& os, Person info)
	{
		os << " Phone: " << info.phone
			<< endl;
		return os;
	}
	~Person();
};

