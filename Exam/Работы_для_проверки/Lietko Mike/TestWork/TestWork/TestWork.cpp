// TestWork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include<iostream>
using namespace std;

//Домашний адресс (AdressInfo)
//Город
//Улица
//Номер дома
//Номер офиса/квартиры
class AddressInfo
{
protected:
	string city;
	string street;
	int houseNumber;
	int appartmentNumber;

public:
	AddressInfo()
	{
		this->city = " ";
		this->street = " ";
		this->houseNumber = 0;
		this->appartmentNumber = 0;
	}
	//-------
	~AddressInfo()
	{  
	
	}
	//-------
	AddressInfo(string city, string street, int houseNumber, int appartmentNumber)
	{
		this->city = city;
		this->street = street;
		this->houseNumber = houseNumber;
		this->appartmentNumber = appartmentNumber;
	}
	//----------
	//-------
	void setCity(string city) 
	{ 
		this->city = city; 
	}
	//-------
	void setStreet(string street) 
	{
		this->street = street; 
	}
	//-------
	void setHouseNumber(int houseNumber) 
	{ 
		this->houseNumber = houseNumber;
	}
	//-------
	void setAppartmentNumber(int appartmentNumber)
	{
		this->appartmentNumber = appartmentNumber;
	}
	//-------
	string getCity() 
	{ 
		return this->city; 
	}
	//-------
	string getStreet()
	{
		return this->street;
	}
	//-------
	int getHouseNumber()
	{ 
		return this->houseNumber; 
	}
	//-------
	int getAppartmentNumber() 
	{
		return this->appartmentNumber;
	}
	//-------
	//----------
	void print()
	{
		cout << "Address: " << this->city << ", " 
			<< this->street << ", " 
			<< this->houseNumber << ", " 
			<< this->appartmentNumber << ";" << endl;
	} 
	//-------
	friend ostream&	operator << (ostream& os, const AddressInfo& t);
};

ostream& operator<<(ostream& os, const AddressInfo& a)
{
	os << "Address: " << a.city << ", " 
		<< a.street << ", " 
		<< a.houseNumber << ", " 
		<< a.appartmentNumber << endl;

	return os;
}
//------------------------------------------------------------------------------------------
///Наследование
//Класс AnimalEntity
//Пол
//Возвраст

class AnimalEntity
{
protected:
	bool sex;
	int age;
public:
	AnimalEntity()
	{

	}
	//-------
	~AnimalEntity() 
	{
	
	}
	//-------
	AnimalEntity(bool sex, int age)
	{
		this->sex = sex;
		this->age = age;
	}
	//----------
	//-------
	bool getSex()
	{
		return this->sex;
	}
	//-------
	int getAge()
	{
		return this->age;
	}
	//-------
	void setSex(bool sex) 
	{
		this->sex = sex; 
	}
	//-------
	void setAge(int age)
	{ 
		this->age = age; 
	}
	//-------
	//----------
	void print()
	{
		cout << this->sex << ", " 
			<< this->age << ";" << endl;
	}
	//-------
	friend ostream&	operator << (ostream& os, const AnimalEntity& c);
};


ostream& operator<<(ostream& os, const AnimalEntity& c)
{
	os << c.sex << ", " << c.age << endl;

	return os;
}
//------------------------------------------------------------------------------------------
//Класс HumanEntity
//Имя
//Фамилия
class HumanEntity : public AnimalEntity
{
protected:
	string firstName;
	string lastName;

public:
	HumanEntity() : AnimalEntity()
	{

	}
	//-------
	~HumanEntity()
	{

	}
	//-------
	HumanEntity(string firstName, string lastName, bool sex, int age) : AnimalEntity(sex, age)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}
	//----------
	//-------
	void setFirstName(string firstName) 
	{
		this->firstName = firstName; 
	}
	//-------
	void setLastName(string lastName) 
	{ 
		this->lastName = lastName; 
	}
	//-------
	string getFirstName()
	{
		return this->firstName;
	}
	//-------
	string getLastName()
	{
		return this->lastName;
	}
	//-------
	//----------
	void print()
	{
		cout << firstName << " " 
			<< lastName
			<< ", sex: " << sex 
			<< ", age: " << age << endl;
	}
	//-------
	friend ostream&	operator << (ostream& os, const HumanEntity& b);
};

ostream& operator<<(ostream& os, const HumanEntity& b)
{
	os << b.firstName << " " 
		<< b.lastName 
		<< ", sex: " << ((b.sex == 0) ? ("male") : ("female")) 
		<< ", age: " << b.age << endl;

	return os;
}
//------------------------------------------------------------------------------------------
//Класс Person
//Телефон
//Наследование класса Адрес(AdressInfo)
class Person : public HumanEntity
{
protected:
	string phone;
	AddressInfo *adr;

public:
	Person() : HumanEntity()
	{

	}
	//-------
	~Person()
	{
		delete adr;
	}
	//-------
	Person(string firstName, string lastName, bool sex, int age, AddressInfo adr, string phoneN)
		: HumanEntity(firstName, lastName, sex, age)
	{
		this->phone = phoneN;
		adr = new AddressInfo(adr.getCity(), adr.getStreet(), adr.getHouseNumber(), adr.getAppartmentNumber());
	}
	//----------
	//-------
	void setphone(string phone)
	{
		this->phone = phone;
	}
	//-------
	string getPhoneNuber() 
	{
		return this->phone;
	}
	//-------
	//----------
	void print()
	{
		cout << "Name: " << firstName << endl
			<< "Second Name: " << lastName << endl
			<< "Sex: " << sex << endl
			<< "Age: " << age << endl
			<< "Address:" << adr->getCity() << endl
			<< "Street: " << adr->getStreet() << endl
			<< "House: " << adr->getHouseNumber() << endl
			<< "Appartment: " << adr->getAppartmentNumber() << endl
			<< "Phone: " << phone << endl;
	}
	//-------
	friend ostream&	operator << (ostream& os, const Person& t);
};

ostream& operator<<(ostream& os, const Person& t)
{
	os << "Name: " << t.firstName << endl
		<< "Second Name" << t.lastName << endl
		<< "Sex: " << ((t.sex == 0) ? ("male") : ("female")) << endl
		<< "Age: " << t.age << endl
		<< "Address: " << t.adr->getCity() << endl
		<< "Street: " << t.adr->getStreet() << endl
		<< "House: " << t.adr->getHouseNumber() << endl
		<< "Appartment: " << t.adr->getAppartmentNumber() << endl
		<< "Phone: " << t.phone << endl;

	return os;
}
//------------------------------------------------------------------------------------------
//класс Employee
//Должность
//Банковский счет
//Заработная плата
class Employee : public Person
{
protected:
	string position;
	double bankCount;
	double salary;
public:
	Employee() : Person()
	{

	}
	//-------
	Employee(string firstName, string lastName, bool sex, int age, AddressInfo addr, string phoneN, string position)
		: Person(firstName, lastName, sex, age, addr, phoneN)
	{
		this->bankCount = bankCount;
		this->position = position;
		this->salary = salary;
	}
	//-------
	~Employee() 
	{
	
	}
	//-------
	void print()
	{
		cout <<"Name: "<< firstName <<endl
			<< "Second Name: " << lastName << endl
			<< "Sex: " << ((sex == 0) ? ("male") : ("female")) << endl
			<< "Age: " << age << endl
			<< "Address: " << adr->getCity() << endl
			<< "Street: " << adr->getStreet() << endl
			<< "House: " << adr->getHouseNumber() << endl
			<< "Appartment: " << adr->getAppartmentNumber() << endl
			<< "Phone: " << phone << endl
			<< "Salary: " << salary<< endl;
	}
	//-------
	friend ostream&	operator << (ostream& os, const Employee& t);
};

ostream& operator<<(ostream& os, const Employee& t)
{
	os << t.firstName 
		<< " " << t.lastName << endl
		<< "Sex: " << ((t.sex == 0) ? ("male") : ("female")) << endl
		<< "Age: " << t.age << endl
		<< "Address: " << t.adr->getCity() << endl
		<< "Street: " << t.adr->getStreet() << endl
		<< "House: " << t.adr->getHouseNumber() << endl
		<< "Appartment: " << t.adr->getAppartmentNumber() << endl
		<< "Phone: " << t.phone << endl
		<< "Position: " << t.position << endl
		<< "Bank Count: " << t.bankCount << endl
		<< "Salary: " << t.salary << endl;

	return os;
}
//------------------------------------------------------------------------------------------
//класс Department
//название отдела
//Список сотрудников
//Начальник
class Department
{
protected:

	string name;
	Employee **panel;
	int panelNumber;
	Employee *leader;

public:
	Department(string name, int panelNumber)
	{
		this->name = name;
		this->panelNumber = panelNumber;
		panel = new Employee*[panelNumber];
	}
	//-------
	~Department()
	{
		for (int i = 0; i < panelNumber; i++)
			delete panel[i];
		delete[] panel;

		delete leader;
	}
	//-------
	void setleader(Employee *pSup)
	{
		leader = pSup;
	}
	//-------
	void addEmployee(int n, Employee *buf)
	{
		panel[n] = buf;
	}
	//-------
	void print()
	{
		cout << "Department name: " << name << endl;
		cout << "Leader:" << endl;
		cout << *leader;
		cout << "Employees:" << endl;
		for (int i = 0; i < panelNumber; i++)
			cout << *(panel)[i];
	}
	//-------
	friend ostream&	operator << (ostream& os, const Department& t);
};

ostream& operator<<(ostream& os, const Department& t)
{
	os << "Department name: " << t.name << endl
	   << "Leader:" << endl
	   << *t.leader
	   << "Employees:" << endl;
	for (int i = 0; i < t.panelNumber; i++)
	{
		os << *(t.panel)[i];
	}
	return os;
}

//------------------------------------------------------------------------------------------
int main()
{
    return 0;
}

