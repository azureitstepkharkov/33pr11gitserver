#pragma once
#include <string>
using namespace std;
class AdressInfo
{
private:
	AdressInfo(const AdressInfo& obj) {};
protected:
	string city;
	string street;
	string home_number;
	int office_number;
public:
	AdressInfo() {};
	

	 AdressInfo(string city, string street, string home_number, int office_number);
	 friend ostream& operator<<(ostream& os, AdressInfo info)
	 {
		 os << "City: " << info.city << " Street: " 
			 << info.street << " Home Number: " 
			 << info.home_number << " Office Number: " 
			 << info.office_number << endl;
		 return os;
	 }
	
};

