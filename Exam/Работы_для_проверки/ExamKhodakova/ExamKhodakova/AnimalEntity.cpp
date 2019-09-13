#include "stdafx.h"
#include "AnimalEntity.h"




AnimalEntity::AnimalEntity(bool sex, unsigned int age)
{
	this->sex = sex;
	this->age = age;
}

AnimalEntity::~AnimalEntity()
{
}

ostream & operator<<(ostream & out_data, AnimalEntity & anim)
{
	out_data << anim.sex << " " << anim.age << endl;
	return out_data;
}