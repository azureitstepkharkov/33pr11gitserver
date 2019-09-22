// � ���� ����� ���������� ���������� ������ HumanEntity

#include "HumanEntity.h"

// ����������� �� ���������
HumanEntity::HumanEntity() {
	this->name = "";
	this->surname = "";
}
// ����������� � �������������� ��������������
HumanEntity::HumanEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6) :
	AdressInfo(value1, value2, value3, value4), name(value5), surname(value6) {
}
// ����������� �����������
HumanEntity::HumanEntity(const HumanEntity & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
}
// �������
void HumanEntity::setName(string name) {
	this->name = name;
}
void HumanEntity::setSurname(string surname) {
	this->surname = surname;
}
// �������
string HumanEntity::getName() const {
	return this->name;
}
string HumanEntity::getSurname() const {
	return this->surname;
}
// ����������
HumanEntity::~HumanEntity() {
	// cout << "HumanEntity object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}

