#pragma once
#include<string>
using namespace std;
class Phone
{
protected:
	string TypePhone;
	string Number;

	Phone() {};
	Phone(Phone& phone) {  };
public:
	Phone(string number,string typePhone=" ");
	

	friend ostream& operator<<(ostream& out_data, Phone& phone);

	void setTypePhone(string typePhone) { this->TypePhone = typePhone; };
	void setNumber(string number) {  this->Number = number; };

	string getTypePhone() { return this->TypePhone; };
	string getNumber() { return this->Number; };

	~Phone();
};

