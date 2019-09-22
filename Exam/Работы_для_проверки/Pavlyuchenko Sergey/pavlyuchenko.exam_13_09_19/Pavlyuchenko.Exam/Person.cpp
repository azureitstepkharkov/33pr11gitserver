// � ���� ����� ���������� ��������� ������� ������ Person

#include "Person.h"

// ����������� �� ���������
Person::Person() {
	this->phone = "";
}
// ����������� � �������������� ��������������
Person::Person(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7) :
	HumanEntity(value1, value2, value3, value4, value5, value6), phone(value7) {
}
// ����������� �����������
Person::Person(const Person & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
}
// �������
void Person::setPhone(string phone) {
	this->phone = phone;
}
// �������
string Person::getPhone() const {
	return this->phone;
}
// ����������
Person::~Person() {
	// cout << "Person object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}

