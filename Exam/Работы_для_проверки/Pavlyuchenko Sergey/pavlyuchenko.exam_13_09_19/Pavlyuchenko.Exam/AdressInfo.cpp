// � ���� ����� ���������� ���������� ������ AdressInfo

#include "AdressInfo.h"

// ����������� �� ���������
AdressInfo::AdressInfo() {
	this->city = "";
	this->street = "";
	this->house = 0;
	this->flat = 0;
}
// ����������� � �������������� ��������������
AdressInfo::AdressInfo(string value1, string value2, unsigned short int value3, unsigned short int value4) :
	city(value1), street(value2), house(value3), flat(value4) {
}
// �������
void AdressInfo::setCity(string city) {
	this->city = city;
}
void AdressInfo::setStreet(string street) {
	this->street = street;
}
void AdressInfo::setHouse(unsigned short int house) {
	this->house = house;
}
void AdressInfo::setFlat(unsigned short int flat) {
	this->flat = flat;
}
// �������
string AdressInfo::getCity() const {
	return this->city;
}
string AdressInfo::getStreet() const {
	return this->street;
}
unsigned short int AdressInfo::getHouse() const {
	return this->house;
}
unsigned short int AdressInfo::getFlat() const {
	return this->flat;
}




