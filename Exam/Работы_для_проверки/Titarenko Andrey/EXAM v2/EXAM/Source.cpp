

//#include "stdafx.h"
#include <iostream>
#include<string>
#include<list>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;



struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};


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






















class Employee : public Person, public ISalaryCalculator
{
protected:
	
	double percent;//%
	double hour;//кол-во часов
	double sum;//сумма
	
	double rateh;//стоимость 1 часа
	double oklad;//оклад
						
	string position;
	string numbercard;
	ISalaryCalculator* salaryCalc;


public:
	Employee(const Employee & obj) {};
	Employee() { salaryCalc = NULL; };
	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}

	string getPossition()
	{
		return position;
	}






	class Rule1 : public ISalaryCalculator
	{
	protected:
		double hour;
		double rate;
	public:
		Rule1()
		{
			hour = 0;
			rate = 0;
		}
		Rule1(double hour, double rate)
		{
			this->hour = hour;
			this->rate = rate;
		}
		virtual double calcSalary()
		{
			return hour * rate;
		}
	};



	//ѕќ„ј—ќ¬јя
	Employee(string Fname, string Lname, string position,
		double h, double rate, string numbercard)
		:Person(Fname, Lname)
	{
		this->numbercard = numbercard;
		this->position = position;
		this->hour = h;
		this->rateh = rate;
		this->percent = 0;
		this->sum = 0;
		this->oklad = 0;
		this->salaryCalc = new Rule1(this->hour, this->rateh);
	}



	// преми€

	class Rule2 : public ISalaryCalculator
	{
	protected:
		double oklad;
		double premium;
	public:
		Rule2()
		{
			oklad = 0;
			premium = 0;
		}
		Rule2(double hour, double premium)
		{
			this->oklad = hour;
			this->premium = premium;
		}
		virtual double calcSalary()
		{
			return oklad + premium;
		}
	};


	Employee(string Fname, string Lname, string position,
		double oklad, double percent, double sum)
		:Person(Fname, Lname)
	{
		this->numbercard = numbercard;
		this->position = position;
		this->oklad = oklad;
		this->sum = 0;
		this->percent = percent;
		this->hour = 0;
		this->rateh = 0;
		this->salaryCalc = new Rule2(oklad, percent);
	}







class Department
{
private:
	Department() {};
	string name;
//	Employee boss;
	Employee* boss;
	list <Employee*> collective;
public:
	Department(string NameOfDep, Employee* boss, vector<Employee*> collective)
	{
		this->collective = collective;
		this->name = name;
		this->boss = boss;
		
	}



	~Department() {};
};






	void Employeead(string Fname, string Lname, string position,double base, string numbercard)
	{
		Employee* m = new Employee(Fname, Lname, position, base, numbercard);
		
	}























void main()
{/*


	Person a("+380634147463", "", "Kharkiv", "street", "moskovska", "12b", 23, "Ivan", "Ivanov", 4, 35);

	cout << a;
}
*/

	vector<Employee*> MEN;
	Employee* m1 = new Employee("Ivan", "Ivanov", "Ivanovich", 5200, "7694 5787 3490 5872");


	Employee* m2 = new Employee("Andrey", "Titarenko", "Razrab", 56, 27, "7694 5787 3490 5872");
	MEN.push_back(m1);
	MEN.push_back(m2);

	for (int i = 0; i < MEN.size(); i++)
	{
		cout << *MEN[i] << endl;
	vector<Employee*>::iterator ptr;
	for (ptr=MEN.begin(); ptr < MEN.end(); ptr);
	cout << *(*ptr) << " ";


	system("pause");
	
}

