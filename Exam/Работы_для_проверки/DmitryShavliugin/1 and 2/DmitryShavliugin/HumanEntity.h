#pragma once
#include"pch.h"

class HumanEntity : public AnimalEntity
{
protected:
	string FirstName;
	string LastName;
	HumanEntity() {};
public:
	HumanEntity(const HumanEntity& obj) { 
		this->FirstName = obj.FirstName;
		this->LastName = obj.LastName;
	};
	HumanEntity(string FistName_value, string LastName_value) {
		this->FirstName = FistName_value;
		this->LastName = LastName_value;
	};

	void setFirstName(string FirstName_value) { this->FirstName = FirstName; };
	void setLastName(string LastName_value) { this->LastName = LastName; };
	string getFirstName() { return FirstName; };
	string getLastName() { return LastName; };

	friend ostream& operator << (ostream& os, HumanEntity& a)
	{
		os << "HumanEntity(First Name: "<< a.FirstName << ", Last Name: " << a.LastName << ")";
		return os;
	};

	~HumanEntity() {};
};

