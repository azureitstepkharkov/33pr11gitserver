#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
protected:
	string Position;
	string BankAccount;
	unsigned int Salary;

	Employee() {};
	Employee(Employee& emp) {};
public:
	//Employee(string pos, string acc, string salary, string phone, string ct, string tpstrt, string strt, string hsnum,
	//	unsigned int apart, string name, string surname, string sex, unsigned int age)
		//:Person(phone, ct, tpstrt, strt, hsnum, apart, name, surname, sex, age);
	

	void setPosition(string position) { this->Position = position; };
	void setBankAccount(string bankAccount) {	this->BankAccount = bankAccount;	};
	void setSalary(unsigned int salary) { this->Salary=salary; };

	string getPosition() { return this->Position; };
	string getBankAccount() { return this->BankAccount; };
	unsigned int getSalary() { return this->Salary; };


	friend ostream& operator<<(ostream& out_data, Employee& empl);

	~Employee() ;
};