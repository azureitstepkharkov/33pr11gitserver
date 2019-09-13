#pragma once
#include "AnimalEntity.h"
#include <string>
using namespace std;
class HumanEntity
{
private:
	//HumanEntity() {};
	//HumanEntity(HumanEntity& obj) {};
protected:
	string FirstName;
	string LastName;
public:
	HumanEntity() {};
	HumanEntity(string FirstName, string LastName);
	friend ostream& operator<<(ostream& os, HumanEntity info)
	{
		os << " FirstName: " << info.FirstName 
			<< endl
			<< " LastName: " << info.LastName
			<< endl;
		return os;
	}
	~HumanEntity();
};

