// � ���� ����� ���������� ��������� ������� ������ Employee

#include "Employee.h"

// ����������� �� ���������
Employee::Employee() {
	this->position = "";
	this->account = 0;
	this->salary = 0;
}
// ����������� � �������������� ��������������
Employee::Employee(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7, string value8, unsigned short int value9, float value10) :
	Person(value1, value2, value3, value4, value5, value6, value7), position(value8), account(value9), salary(value10) {
}
// ����������� �����������
Employee::Employee(const Employee & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
}
// �������
void Employee::setPosition(string position) {
	this->position = position;
}
void Employee::setAccount(unsigned short int account) {
	this->account = account;
}
void Employee::setSalary(float salary) {
	this->salary = salary;
}
// �������
string Employee::getPosition() const {
	return this->position;
}
unsigned short int Employee::getAccount() const {
	return this->account;
}
float Employee::getSalary() const {
	return this->salary;
}
// �������� ostream
ostream& operator<<(ostream &out, const Employee &obj) {
	out << "�����: " << obj.getCity() << endl;
	out << "�����: " << obj.getStreet() << endl;
	out << "���: " << obj.getHouse() << endl;
	out << "��������: " << obj.getFlat() << endl;
	out << "���: " << obj.getName() << endl;
	out << "�������: " << obj.getSurname() << endl;
	out << "�������: " << obj.getPhone() << endl;
	out << "���������: " << obj.getPosition() << endl;
	out << "��������� ����: " << obj.getAccount() << endl;
	out << "��������: " << obj.getSalary() << endl;

	return out;
}
// �������� istream
istream& operator>>(istream &in, Employee &obj) {
	cout << "�����: ";
	in >> obj.city;
	cout << "�����: ";
	in >> obj.street;
	cout << "���: ";
	in >> obj.house;
	cout << "��������: ";
	in >> obj.flat;
	cout << "���: ";
	in >> obj.name;
	cout << "�������: ";
	in >> obj.surname;
	cout << "�������: ";
	in >> obj.phone;
	cout << "���������: ";
	in >> obj.position;
	cout << "��������� ����: ";
	in >> obj.account;
	cout << "��������: ";
	in >> obj.salary;

	return in;
}
// ����������
Employee::~Employee() {
	// cout << "Employee object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}

