#include "stdafx.h"
#include "HumanEntity.h"
//#include"AnimalEntity.h"



HumanEntity::~HumanEntity()
{
}

HumanEntity::HumanEntity(string name, string surname,		//человек
							bool sex, unsigned int age)			//животное
	:AnimalEntity(sex, age)	//наследование
{
	this->Name = name;
	this->Surname = surname;

}

HumanEntity::HumanEntity(string name, string surname)
{
	this->Name = name;
	this->Surname = surname;

}

ostream & operator<<(ostream & out_data, HumanEntity & man)
{
	out_data << man.Name << " " << man.Surname << endl;
	return out_data;
}