#pragma once
#include<string>
#include"AnimalEntity.h"
using namespace std;
class HumanEntity:public AnimalEntity
{
protected:
	string Name;
	string Surname;

public://protected:
	HumanEntity() {};
	HumanEntity(HumanEntity& human) {};

public:

	HumanEntity(string name, string surname, //человек
					bool sex, unsigned int age);//животное
	HumanEntity(string name, string surname);
	
	friend ostream& operator<<(ostream& out_data, HumanEntity& man);

	void set_name(string name) { this->Name = name; }
	void set_sname(string sname) { this->Surname = sname; }

	string get_name() { return this->Name; }
	string get_sname() { return this->Surname; }

	~HumanEntity() {};
};