#pragma once
#include"pch.h"

class Employee : public Person
{
protected:
	string position;
	int bankAccount;
	double salary;
	Employee() {};
public:
	Employee(const Employee& obj) { 
		this->position = obj.position;
		this->bankAccount = obj.bankAccount;
		this->salary = obj.salary;
	};

	//Full Employee Constructor
	//First Name, Second Name, Sex, Age, Number, Position, Bank Account, Salary, City, Street, House Number, Apartment Number
	Employee(string FN_value, string LN_value, string Sex_value, int Age_value, 
			 string Number_value, string Position_value, int BankAccount_value, 
			 double Salary_value, string City_value, string Street_value, int HouseNumber_value, int ApartmentNumber_value) 
	{
		this->FirstName = FN_value;
		this->LastName = LN_value;
		this->sex = Sex_value;
		this->age = Age_value;
		this->number = Number_value;
		this->position = Position_value;
		this->bankAccount = BankAccount_value;
		this->salary = Salary_value;
		this->city = City_value;
		this->street = Street_value;
		this->houseNumber = HouseNumber_value;
		this->apartmentNumber = ApartmentNumber_value;
	};

	void printEmployee(Employee& obj) { 
		cout << obj.getFirstName() << obj.getLastName() << endl;
	}

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
		return os;
	};

	~Employee() {};
};

