#include "stdafx.h"
#include "Person.h"
#include"HumanEntity.h"



Person::~Person()
{
}




Person::Person(Phone phone(string number, string type),
			string City, string TypeStreet, string nameStreet, string housNum, unsigned int ApartmentNum,//личность
				string Name, string surname, //человек
					bool sex, unsigned int age)//животное
	:HumanEntity(string Name, string surname, bool sex, unsigned int age)
{
}

void Person::addPhone(Phone phone)
{
	//if (phone != nullptr) {}

}

ostream & operator<<(ostream & out_data, Person & person)
{
	out_data << person.phone << " " << person.adress << " " << person.Name << " " << person.Surname << endl;

	return out_data;
}
