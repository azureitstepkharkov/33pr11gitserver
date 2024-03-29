#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AddressInfo
{
protected:
	string City;
	string Street;
	int NumberHome;
	int Apartment_number;
public:
	AddressInfo()
	{
		this->City = " - ";
		this->Street = " - ";
		this->NumberHome = 0;
		this->Apartment_number = 0;
	}
	AddressInfo(string City, string street, int NumberHome, int Apartment_number)
	{
		this->City = City;
		this->Street = street;
		this->NumberHome = NumberHome;
		this->Apartment_number = Apartment_number;
	}
	~AddressInfo() {  }

	void setCity(string City) 
	{
		this->City = City; 
	}

	void setStreet(string street)
	{ 
		this->Street = street; 
	}

	void setNumberHome(int NumberHome)
	{
		this->NumberHome = NumberHome;
	}

	void setApartment_number(int nAppartment)
	{
		this->Apartment_number = Apartment_number; 
	}

	string getCity()
	{
		return this->City; 
	}

	string getStreet() 
	{
		return this->Street;
	}

	int getNumberHome()
	{
		return this->NumberHome;
	}

	int getApartment_number() 
	{
		return this->Apartment_number;
	}

	void print()
	{
		cout << "Addr: " << this->City << ", " << this->Street << ", " << this->NumberHome << ", " << this->Apartment_number << endl;
	}

	friend ostream&	operator << (ostream& os, const AddressInfo& t);
};
ostream& operator<<(ostream& os, const AddressInfo& t)
{
	os << "Addr: " << t.City << ", " << t.Street << ", " << t.NumberHome << ", " << t.Apartment_number << endl;

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

	~AnimalEntity() {}

	void setSex(bool sex) 
	{
		this->sex = sex; 
	}

	void setAge(int age)
	{
		this->age = age;
	}

	bool getSex() 
	{
		return this->sex; 
	}

	int getAge() 
	{
		return this->age; 
	}

	void print()
	{
		cout << this->sex << ", " << this->age << endl;
	}

	friend ostream&	operator << (ostream& os, const AnimalEntity& t);
};


ostream& operator<<(ostream& os, const AnimalEntity& t)
{
	os << t.sex << ", " << t.age << endl;

	return os;
}

class HumanEntity : public AnimalEntity
{
protected:
	string firstName;
	string lastName;

public:
	HumanEntity() : AnimalEntity()
	{

	}
	HumanEntity(string firstName, string lastName, bool sex, int age) : AnimalEntity(sex, age)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}

	~HumanEntity() { }

	void setFirstName(string firstName) 
	{
		this->firstName = firstName; 
	}

	void setLastName(string lastName) 
	{
		this->lastName = lastName;
	}

	string getFirstName()
	{ 
		return this->firstName;
	}

	string getLastName()
	{ 
		return this->lastName;
	}

	void print()
	{
		cout << firstName << " " << lastName << ", sex: " << sex << ", age: " << age << endl;
	}

	friend ostream&	operator << (ostream& os, const HumanEntity& t);
};

ostream& operator<<(ostream& os, const HumanEntity& t)
{
	os << t.firstName << " " << t.lastName << ", sex: " << ((t.sex == 0) ? ("male") : ("female")) << ", age: " << t.age << endl;

	return os;
}

class Person : public HumanEntity
{
protected:
	string phoneNumber;
	AddressInfo *pAddress;

public:
	Person() : HumanEntity()
	{

	}
	Person(string firstName, string lastName, bool sex, int age, AddressInfo addr, string phoneNuber): HumanEntity(firstName, lastName, sex, age)
	{
		this->phoneNumber = phoneNuber;
		pAddress = new AddressInfo(addr.getCity(), addr.getStreet(), addr.getNumberHome(), addr.getApartment_number());
	}
	~Person()
	{
		delete pAddress;
	}

	void setPhoneNumber(string phoneNumber)
	{ 
		this->phoneNumber = phoneNumber;
	}

	string getPhoneNuber()
	{
		return this->phoneNumber;
	}

	void print()
	{
		cout << firstName << " " << lastName << ", sex: " << sex << ", age: " << age <<
			", Addr:" << pAddress->getCity() << " st. " << pAddress->getStreet() << " b." << pAddress->getNumberHome() << ", app." << pAddress->getApartment_number() <<
			", phone: " << phoneNumber << endl;
	}

	friend ostream&	operator << (ostream& os, const Person& t);
};

ostream& operator<<(ostream& os, const Person& t)
{
	os << t.firstName << " " << t.lastName << ", sex: " << ((t.sex == 0) ? ("male") : ("female")) << ", age: " << t.age <<
		", Addr:" << t.pAddress->getCity() << " st." << t.pAddress->getStreet() << " b." << t.pAddress->getNumberHome() << ", app." << t.pAddress->getApartment_number() <<
		", phone: " << t.phoneNumber << endl;

	return os;
}
struct ISalaryCalculator
{
	virtual double calcSalary() = 0;
};

class Rule_Salary : public ISalaryCalculator
{
protected:
	double base;
public:
	Rule_Salary() 
	{
		base = 0;
	}
	Rule_Salary(double base)
	{
		this->base = base; 
	}
	virtual double calcSalary()
	{
		return base;
	}
};

class Rule_SalaryAward : public ISalaryCalculator
{
protected:
	double base;
	double bonus;
public:
	Rule_SalaryAward()
	{
		base = 0;
		bonus = 0; 
	}
	Rule_SalaryAward(double base, double bonus)
	{ 
		this->base = base;
		this->bonus = bonus;
	}
	virtual double calcSalary()
	{
		return base + bonus;
	}
};

class Rule_Hourly : public ISalaryCalculator
{
protected:
	double hour;
	double rate;
public:
	Rule_Hourly()
	{ 
		hour = 0;
		rate = 0;
	}
	Rule_Hourly(double hour, double rate)
	{
		this->hour = hour; this->rate = rate;
	}
	virtual double calcSalary()
	{
		return hour * rate;
	}
};


class Rule_BaseRevenue : public ISalaryCalculator
{
protected:
	double base;
	double percent;
	double seals;
public:
	Rule_BaseRevenue()
	{ 
		base = 0;
		percent = 0; 
		seals = 0; 
	}
	Rule_BaseRevenue(double base, double percent, double seals)
	{
		this->base = base; this->percent = percent; this->seals = seals;
	}
	virtual double calcSalary()
	{
		return base + seals * percent;
	}
};

struct CalcInfo
{
	double base;
	double percent;
	double total;
	double bonus;
	double bonus_percent;
	double hour;
	double rate_per_hour;
	double sales;
};

class Employee : public Person, public ISalaryCalculator
{
protected:
	string position;
	double bankCount;

	double base;
	double rate_per_hour;
	double percent;
	double hour;
	double total;

	ISalaryCalculator* salaryCalc;

public:
	Employee() : Person()
	{

	}

	Employee(string firstName, string lastName, bool sex, int age, AddressInfo addr, string phoneNuber, string position, int codePosition, double bankCount, CalcInfo info)
		: Person(firstName, lastName, sex, age, addr, phoneNuber)
	{
		this->bankCount = bankCount;

		this->position = position;
		this->base = info.base;
		this->total = info.bonus;
		this->percent = info.percent;
		this->hour = info.hour;
		this->rate_per_hour = info.rate_per_hour;
		this->salaryCalc = createSalarycalcRule(codePosition, info);
	}

	static ISalaryCalculator* createSalarycalcRule(int codePosition, CalcInfo info)
	{
		ISalaryCalculator* salaryCalc = NULL;
		switch (codePosition)
		{
		case 1: salaryCalc = new Rule_Salary(info.base); break;
		case 2: salaryCalc = new Rule_SalaryAward(info.base, info.bonus); break;
		case 3: salaryCalc = new Rule_Hourly(info.hour, info.rate_per_hour); break;
		case 4: salaryCalc = new Rule_BaseRevenue(info.base, info.percent, info.sales); break;
		default: salaryCalc = new Rule_Salary(info.base);
			break;
		}
		return salaryCalc;
	}

	~Employee() {}

	virtual double calcSalary()
	{
		if (this->salaryCalc == NULL)
			return 0;
		else
			return this->salaryCalc->calcSalary();
	}

	void print()
	{
		cout << firstName << " " << lastName << ", sex: " << ((sex == 0) ? ("male") : ("female")) << ", age: " << age <<
			", Addr:" << pAddress->getCity() << " st." << pAddress->getStreet() << " b." << pAddress->getNumberHome() << ", app." << pAddress->getApartment_number() <<
			", phone: " << phoneNumber <<
			" Pos: " << position << ", bank: " << bankCount << ", sal: " << calcSalary() << endl;
	}

	friend ostream&	operator << (ostream& os, const Employee& t);
};

ostream& operator<<(ostream& os, const Employee& t)
{
	os << t.firstName << " " << t.lastName << ", sex: " << ((t.sex == 0) ? ("male") : ("female")) << ", age: " << t.age <<
		", Addr:" << t.pAddress->getCity() << " st." << t.pAddress->getStreet() << " b." << t.pAddress->getNumberHome() << ", app." << t.pAddress->getApartment_number() <<
		", phone: " << t.phoneNumber <<
		" Pos: " << t.position << ", bank: " << t.bankCount << ", sal: " << t.salaryCalc->calcSalary() << endl;

	return os;
}

class Department
{
protected:

	string name;
	Employee **staff;
	int nStaff;
	Employee *supervisor;

public:
	Department(string name, int nStaff)
	{
		this->name = name;
		this->nStaff = nStaff;
		staff = new Employee*[nStaff];
	}
	~Department()
	{
		for (int i = 0; i < nStaff; i++)
			delete staff[i];
		delete[] staff;

		delete supervisor;
	}

	void setSupervisor(Employee *pSup)
	{
		supervisor = pSup;
	}

	void addEmployee(int n, Employee *pEmp)
	{
		staff[n] = pEmp;
	}

	void print()
	{
		cout << "Department name: " << name << endl;
		cout << "Supervisor:" << endl;
		cout << *supervisor;
		cout << "Employees:" << endl;
		for (int i = 0; i < nStaff; i++)
			cout << *(staff)[i];
	}

	friend ostream&	operator << (ostream& os, const Department& t);
};

ostream& operator<<(ostream& os, const Department& t)
{
	os << "Department name: " << t.name << endl;
	os << "Supervisor:" << endl;
	os << *t.supervisor;
	os << "Employees:" << endl;
	for (int i = 0; i < t.nStaff; i++)
		os << *(t.staff)[i];

	return os;
}
int main()
{
	Department Department_2("IT", 4);

	CalcInfo info;
	info.base = 1000;
	info.bonus = 0;
	info.bonus_percent = 0.1;
	info.hour = 120;
	info.rate_per_hour = 12;
	info.percent = 0.1;
	info.total = 0;
	info.sales = 10000;

	Employee *Employee_1 = new Employee("Jame", "Miku", 0, 40, AddressInfo("California", "Main", 1, 0), "+380", "Supervisor", 4, 10000, info);
	Department_2.setSupervisor(Employee_1);
	Employee *Employee_2 = new Employee("Adren", "Miku", 0, 41, AddressInfo("California", "Main", 1, 0), "+380", "Sales Manager", 3, 10000, info);
	Department_2.addEmployee(0, Employee_2);
	Employee *Employee_3 = new Employee("Nikolai", "Miku", 0, 41, AddressInfo("California", "Main", 1, 0), "+380", "Software Engeener", 2, 10000, info);
	Department_2.addEmployee(1, Employee_3);
	Employee *Employee_4 = new Employee("Niko", "Miku", 0, 42, AddressInfo("California", "Main", 1, 0), "+380", "Driver", 4, 10000, info);
	Department_2.addEmployee(2, Employee_4);
	Employee *Employee_5 = new Employee("Blade", "Miku", 0, 42, AddressInfo("California", "Main", 1, 0), "+380", "Accountant", 3, 10000, info);
	Department_2.addEmployee(3, Employee_5);

	cout << Department_2 << endl;

	vector <Employee*> men;
	vector <Employee*>::iterator ptr;
	men.push_back(Employee_1);
	men.push_back(Employee_2);
	men.push_back(Employee_3);
	men.push_back(Employee_4);
	men.push_back(Employee_5);
	for (ptr = men.begin(); ptr < men.end(); ptr++)
		cout << *(*ptr) << endl;

	system("pause");
	return 0;
}