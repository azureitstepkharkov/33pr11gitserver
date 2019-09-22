#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
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
	AddressInfo(string city, string street, int houseNumber, int appartmentNumber)
	{
		this->city = city;
		this->street = street;
		this->houseNumber = houseNumber;
		this->appartmentNumber = appartmentNumber;
	}
	~AddressInfo() {  }
	void setCity(string city)
	{
		this->city = city;
	}
	void setStreet(string street)
	{
		this->street = street;
	}
	void setHouseNumber(int houseNumber)
	{
		this->houseNumber = houseNumber;
	}
	void setAppartmentNumber(int appartmentNumber)
	{
		this->appartmentNumber = appartmentNumber;
	}
	string getCity()
	{
		return this->city;
	}
	string getStreet()
	{
		return this->street;
	}
	int getHouseNumber()
	{
		return this->houseNumber;
	}
	int getAppartmentNumber()
	{
		return this->appartmentNumber;
	}
	void print()
	{
		cout << "Address: " << this->city << ", "
			<< this->street << ", "
			<< this->houseNumber << ", "
			<< this->appartmentNumber << ";" << endl;
	}
	friend ostream& operator << (ostream& os, const AddressInfo& t);
};
ostream& operator<<(ostream& os, const AddressInfo& t)
{
	os << "Addr: " << t.city << ", " << t.street << ", " << t.houseNumber << ", " << t.appartmentNumber << endl;
	return os;
}
class AnimalEntity
{
protected:
	bool sex;
	int age;
public:
	AnimalEntity()
	{

	}
	AnimalEntity(bool sex, int age)
	{
		this->sex = sex;
		this->age = age;
	}
	void setSex(bool sex)
	{
		this->sex = sex;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	int getSex()
	{
		return this->sex;
	}
	int getAge()
	{
		return this->age;
	}
	void print()
	{
		cout << this->sex << ", " << this->age << "; " << endl;
	}
	friend ostream& operator << (ostream& os, const AnimalEntity& t);
};
ostream& operator<<(ostream& os, const AnimalEntity& t)
{
	os << t.sex << ", " << t.age << endl;
	return os;
}
class HumanEntity : public AnimalEntity
{
protected:
	string FirstName;
	string LastName;
	bool sex;
	int age;
public:
	HumanEntity() : AnimalEntity()
	{

	}
	HumanEntity(string FirstName, string LastName, bool sex, int age) : AnimalEntity(sex,age)
	{
		this->FirstName = FirstName;
		this->LastName = LastName;
	}
	~HumanEntity() { }
		void setFirstName(string FirstName)
	{
		this->FirstName = FirstName;
	}
		void setLastName(string LastName)
	{
		this->LastName = LastName;
	}
	string getFirstName()
	{
		return this->FirstName;
	}
	string getLastName()
	{
		return this->LastName;
	}
	void print()
	{
		cout << this->FirstName << ", " << this->LastName << "; " << endl;
	}
	friend ostream& operator << (ostream& os, const HumanEntity& t);
};
ostream& operator<<(ostream& os, const HumanEntity& t)
{
	os << t.FirstName << " " << t.LastName << ", sex: " << ((t.sex == 0) ? ("male") : ("female")) << ", age: " << t.age << endl;
	return os;
}
class Person : public HumanEntity
{
protected:
	string phoneNumber;
	AddressInfo* pAddress;
public:
	Person() : HumanEntity()
	{

	}
	Person(string FirstName, string LastName, bool sex, int age, AddressInfo addr, string phoneNumber) : HumanEntity(FirstName, LastName, sex, age)
	{
		this->phoneNumber = phoneNumber;
		pAddress = new AddressInfo(addr.getCity(), addr.getStreet(), addr.getHouseNumber(), addr.getAppartmentNumber());
	}
	~Person()
	{
		delete pAddress;
	}
	void setPhoneNumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}
	string getPhoneNumber()
	{
		return this->phoneNumber;
	}
	void print()
	{
		cout << FirstName << " " << LastName << ", sex: " << sex << ", age: " << age << ", Addr:" << pAddress->getCity() << " st. " << pAddress->getStreet() << " b." << pAddress->getHouseNumber() << ", app." << pAddress->getAppartmentNumber() << ", phone: " << phoneNumber << endl;
	}
	friend ostream& operator << (ostream& os, const Person& t);
};

ostream& operator<<(ostream& os, const Person& t)
{
	os << t.FirstName << " " << t.LastName << ", sex: " << ((t.sex == 0) ? ("male") : ("female")) << ", age: " << t.age << ", Addr:" << t.pAddress->getCity() << " st." << t.pAddress->getStreet() << " b." << t.pAddress->getHouseNumber() << ", app." << t.pAddress->getAppartmentNumber() << ", phone: " << t.phoneNumber << endl;
	return os;
}

int main()
{
	
	system("pause");
    return 0;
}

