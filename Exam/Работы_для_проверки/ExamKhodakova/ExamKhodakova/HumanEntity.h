#pragma once
#include<string>
using namespace std;
class HumanEntity
{
protected:
	string Name;
	string Surname;
protected:
	HumanEntity() {};
	HumanEntity(HumanEntity& human) {};

public:
	HumanEntity(string name, string surname, string sex, unsigned int age);
	HumanEntity(string name, string surname);
	
	friend ostream& operator<<(ostream& out_data, HumanEntity& man);

	void set_name(string name) { this->Name = name; }
	void set_sname(string sname) { this->Surname = sname; }

	string get_name() { return this->Name; }
	string get_sname() { return this->Surname; }

	~HumanEntity() {};
};