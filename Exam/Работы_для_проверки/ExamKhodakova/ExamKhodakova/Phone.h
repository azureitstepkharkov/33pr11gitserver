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
	Phone(string number,string typePhone);
	Phone(string number);

	friend ostream& operator<<(ostream& out_data, Phone& phone);

	~Phone();
};

