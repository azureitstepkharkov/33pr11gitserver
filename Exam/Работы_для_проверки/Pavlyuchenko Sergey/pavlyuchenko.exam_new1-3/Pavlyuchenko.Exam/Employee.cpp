// � ���� ����� ���������� ���������� ������� ������ Employee

#include "Employee.h"

// ����������� �� ���������
Employee::Employee() {
	this->position = "";
	this->account = 0;
	this->salary = 0;
	this->salaryCalc = nullptr;
}
// ����������� � �������������� ��������������
Employee::Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary) :
	Person(sex, age, name, surname, phone, city, street, house, flat), position(position), account(account), salary(salary) {
}
// ������������� ����������� � ������ ������� ��
Employee::Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary, unsigned short int codePosition) :
	Person(sex, age, name, surname, phone, city, street, house, flat), position(position), account(account), salary(salary), codePosition(codePosition) {
	this->salaryCalc = createSalaryCalcRule(codePosition);
}
// ����������� �����������
Employee::Employee(const Employee & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
	this->codePosition = obj.codePosition;
	this->salaryCalc = obj.salaryCalc;
}
// �������� ������������
Employee Employee::operator=(const Employee & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
	this->codePosition = obj.codePosition;
	this->salaryCalc = obj.salaryCalc;
	return *this;
}
// �������
void Employee::setSex(string sex) {
	this->sex = sex;
}
void Employee::setAge(unsigned short int age) {
	this->age = age;
}
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setSurname(string surname) {
	this->surname = surname;
}
void Employee::setPhone(string phone) {
	this->phone = phone;
}
void Employee::setCity(string city) {
	this->city = city;
}
void Employee::setStreet(string street) {
	this->street = street;
}
void Employee::setHouse(unsigned short int house) {
	this->house = house;
}
void Employee::setFlat(unsigned short int flat) {
	this->flat = flat;
}
void Employee::setPosition(string position) {
	this->position = position;
}
void Employee::setAccount(unsigned short int account) {
	this->account = account;
}
void Employee::setSalary(double salary) {
	this->salary = salary;
}
void Employee::setCodePosition(unsigned short int codePosition) {
	this->codePosition = codePosition;
}
void Employee::setSalaryCalcRule(unsigned short int codePosition) {
	this->salaryCalc = createSalaryCalcRule(codePosition);
}
// �������
string Employee::getSex() const {
	return this->sex;
}
unsigned short int Employee::getAge() const {
	return this->age;
}
string Employee::getName() const {
	return this->name;
}
string Employee::getSurname() const {
	return this->surname;
}
string Employee::getPhone() const {
	return this->phone;
}
string Employee::getCity() const {
	return this->city;
}
string Employee::getStreet() const {
	return this->street;
}
unsigned short int Employee::getHouse() const {
	return this->house;
}
unsigned short int Employee::getFlat() const {
	return this->flat;
}
string Employee::getPosition() const {
	return this->position;
}
unsigned short int Employee::getAccount() const {
	return this->account;
}
double Employee::getSalary() const {
	return this->salary;
}
unsigned short int Employee::getCodePosition() const {
	return this->codePosition;
}
// �������� ostream
ostream& operator<<(ostream &out, const Employee obj) {
	out << "���: " << obj.getSex() << endl;
	out << "�������: " << obj.getAge() << endl;
	out << "���: " << obj.getName() << endl;
	out << "�������: " << obj.getSurname() << endl;
	out << "�������: " << obj.getPhone() << endl;
	out << "�����: " << obj.getCity() << endl;
	out << "�����: " << obj.getStreet() << endl;
	out << "����� ����: " << obj.getHouse() << endl;
	out << "����� ��������: " << obj.getFlat() << endl;
	out << "���������: " << obj.getPosition() << endl;
	out << "��������� ����: " << obj.getAccount() << endl;
	out << "��� ���������: " << obj.getCodePosition() << endl;
	switch (obj.getCodePosition())	{
	case 1:
		out << "������� ������� ��: �����" << endl;
		break;
	case 2:
		out << "������� ������� ��: ����� � ������" << endl;
		break;
	case 3:
		out << "������� ������� ��: ������ �� �����" << endl;
		break;
	case 4:
		out << "������� ������� ��: ������ � % �� �������" << endl;
		break;
	default:
		out << "������� ������� ��: �����" << endl;
		break;
	}
	out << "��������: " << obj.getSalary() << endl;

	return out;
}
// �������� istream
istream& operator>>(istream &in, Employee &obj) {
	system("color 07");
	in.get();
	obj.sex = checkSex(); // ���
	obj.age = checkNumber(in, "�������: "); // �������
	obj.name = checkString(in, "���: "); // ���
	obj.surname = checkString(in, "�������: "); // �������
	obj.phone = checkPhone(in); // �������
	obj.city = checkString(in, "�����: "); // �����
	obj.street = checkString(in, "�����: "); // �����
	obj.house = checkNumber(in, "����� ����: "); // ����� ����
	obj.flat = checkNumber(in, "����� ��������: "); // ����� ��������
	obj.position = checkPosition(in); // ���������
	obj.account = checkNumber(in, "��������� ����: "); // ��������� ����
	obj.codePosition = checkCodePosition(in); // ��� ���������
	// ��������
	obj.salaryCalc = obj.createSalaryCalcRule(obj.codePosition);
	if (obj.salaryCalc == nullptr) {
		obj.salary = 0;
	}
	else {
		obj.salary = obj.salaryCalc->getSalary();
	}

	return in;
}
// ����� ��� ����������� ������ �������� ��
ISalaryCalculator* Employee::createSalaryCalcRule(int codePosition) {
	ISalaryCalculator* tempCalc = nullptr;
	double base;
	double bonus;
	double hour;
	double ratePerHour;
	double percent;
	double earnings;
	switch (codePosition) {
	case 1: 
		base = checkCalc(cin, "������� �����: ");
		tempCalc = new Rule1(base);
		break;
	case 2:
		base = checkCalc(cin, "������� �����: ");
		bonus = checkCalc(cin, "������� ������: ");
		tempCalc = new Rule2(base, bonus);
		break;
	case 3: 
		hour = checkCalc(cin, "������� ���������� �����: ");
		ratePerHour = checkCalc(cin, "������� ��������� ������: ");
		tempCalc = new Rule3(hour, ratePerHour);
		break;
	case 4: 
		base = checkCalc(cin, "������� �����: ");
		percent = checkCalc(cin, "������� % �� �������: ");
		earnings = checkCalc(cin, "������� �������: ");
		tempCalc = new Rule4(base, percent, earnings);
		break;
	default: 
		tempCalc = new Rule1(base);
		break;
	}
	return tempCalc;
}
// ����������
Employee::~Employee() {
	// cout << "Employee object " << this << " deleted!" << endl;
	delete salaryCalc;
	// ���������������, ����� �� ������������ �����
}

