

//#include "stdafx.h"
#include <iostream>
#include<string>
#include<list>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;




class AdressInfo
{
protected:
	string city;
	string street;
	string houseNumber;
	string apartamentNumber;

public:
	AdressInfo() {};
	AdressInfo(const AdressInfo & obj) {}
	AdressInfo(string city,string street,string houseNumber,string apartamentNumber){
		this->city = city;
		this->street = street;
		this->houseNumber = houseNumber;
		this->apartamentNumber = apartamentNumber;
	}

	void setCity(string city)
	{
	this->city = city;
	}
	void setStreet(string street)
	{
	this->street = street;
	}
	void setHouseN(string houseNumber)
	{
	this->houseNumber = houseNumber;
	}
	void setFlatN(string apartamentNumber)
	{
	this->apartamentNumber = apartamentNumber;
	}

	

	friend ostream& operator << (ostream& os, const AdressInfo& adress)
	{
		os << "city " << adress.city << "street " << adress.street  << "houseNumber " << adress.houseNumber<< "apartamentNumber" << adress.apartamentNumber << endl;

	
	}

	~AdressInfo() {};
};






class AnimalEntity
{

public:
	int age;
	int sex;
protected:
	AnimalEntity() { this->age = 18; this->sex = 1; };
	AnimalEntity(int age, int sex)
	{
	this->age = age;
	this->sex = sex;
	}



	AnimalEntity(const AnimalEntity & obj) {};

	void setAge(int age)
	{
		this->age = age;
	}
	void setSex(int sex)
	{
		this->sex = sex;
	}

	friend ostream& operator << (ostream& os, const AnimalEntity& data)
	{
		os << "age " << data.age<< "sex " << data.sex << endl;
		return os;
	}

	~AnimalEntity() {};
};

























class HumanEntity : public AnimalEntity
{

protected:
	string FName;
	string LName;
	HumanEntity() {};
public:

	HumanEntity(string FirstName,
		string LastName,
		int age,
		int sex) 
		
		:AnimalEntity(age, sex)
	{
	this->FName = FirstName;
	this->LName = LastName;
	}




	void setFName(string FirstName)
	{
	this->FName = FirstName;
	}




	void setLastName(string LastName)
	{
	this->LName = LastName;
	}



	friend ostream& operator << (ostream& os, const HumanEntity& data)
	{
		os << "First Name " << data.FName	<< " Last Name " << data.LastName << "age " << data.age;<< "sex " << data.sex << endl;
		return os;
	}

	~HumanEntity() {};
};





















class Person : public HumanEntity
{

protected:
	string phone;
	AdressInfo adress;
	Person() {};
public:
	Person(string phone,
		string city,
		string street,
		string houseNumber,
		string apartamentNumber,
		string Fname,
		string Lname,
		int age,
		int sex) 
		: HumanEntity(Fname, Lname, age, sex)
	{

	this->phone = phone;
	this->adress = new AdressInfo(city, street, houseNumber, apartamentNumber);
	}
	friend ostream& operator << (ostream& os, const Person& data)
	{
		os << "First Name" << data.FirstName<< "Last Name" << data.LastName<< "age\n" << data.age<< "Sex\n"<< data.sex	<< "adress\n"<< *data.adress << endl;
		return os;
	}
	~Person() {};
};
















class Employee
{
private:
	string position;
	string cardnumber;
	float salary;
public:
	Employee() {};
	Employee(string position,
	string Numbercard,
	float salary)
	{
	this->position = position;
	this->cardnumber = cardnumber;
	this->salary = salary;
	}

	
	~Employee() {};
};












class Department
{
private:
	Department() {};
	string name;
	Employee boss;
	list <Employee*> collective;
public:

	~Department() {};
};


void main()
{

	system("pause");
	
}

