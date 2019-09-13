#pragma once
#include"pch.h"

class Employee : public Person
{
protected:
	string position;
	int bankAccount;
	double salary;
	Employee() {};
	Employee(const Employee& obj) { cout << "Employee& obj" << endl; };
public:
	Employee(string position_value, int bankAccount_value, double salary_value) {
		this->position = position_value;
		this->bankAccount = bankAccount_value;
		this->salary = salary_value;
	};
	void setPosition(string position_value) { this->position = position_value; };
	void setBankAccount(int bankAccount_value) { this->bankAccount = bankAccount_value; };
	void setSalary(double salary_value) { this->salary = salary_value; };
	string getPosition() { return position; };
	int getBankAccount() { return bankAccount; };
	double getSalary() { return salary; };

	friend ostream& operator << (ostream& os, Employee& a)
	{
		os << "Employee(Position: " << a.position <<", Bank Account: "<<a.bankAccount<<", Salary: "<<a.salary<<")";
		//os << "Adress(City: " << a.adr->getCity << ", Street: " << a.adr->getStreet << ", House Number: " << a.adr->getHouseNumber << ", Apartment Number: " << a.adr->getApartmentNumber << ")";
		return os;
	};

	~Employee() {};
};

