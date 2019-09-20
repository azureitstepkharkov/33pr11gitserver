// � ���� ����� ���������� ���������� ������ HumanEntity

#include "HumanEntity.h"

// ����������� �� ���������
HumanEntity::HumanEntity() {
	this->name = "";
	this->surname = "";
}
// ����������� � �������������� ��������������
HumanEntity::HumanEntity(string sex, unsigned short int age, string name, string surname) :
	AnimalEntity(sex, age), name(name), surname(surname) {
}
// ����������� �����������
HumanEntity::HumanEntity(const HumanEntity & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
}
// ����������
HumanEntity::~HumanEntity() {
	// cout << "HumanEntity object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}

