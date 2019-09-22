// � ���� ����� ���������� ���������� ������ AnimalEntity

#include "AnimalEntity.h"

// ����������� �� ���������
AnimalEntity::AnimalEntity() {
	this->sex = "";
	this->age = "";
}
// ����������� � �������������� ��������������
AnimalEntity::AnimalEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6) :
	AdressInfo(value1, value2, value3, value4), sex(value5), age(value6) {
}
// ����������� �����������
AnimalEntity::AnimalEntity(const AnimalEntity & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->sex = obj.sex;
	this->age = obj.age;
}
// �������
void AnimalEntity::setSex(string sex) {
	this->sex = sex;
}
void AnimalEntity::setAge(string age) {
	this->age = age;
}
// �������
string AnimalEntity::getSex() const {
	return this->sex;
}
string AnimalEntity::getAge() const {
	return this->age;
}
// ����������
AnimalEntity::~AnimalEntity() {
	// cout << "AnimalEntity object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}

