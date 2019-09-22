// � ���� ����� ���������� ���������� ������ AnimalEntity

#include "AnimalEntity.h"

// ����������� �� ���������
AnimalEntity::AnimalEntity() {
	this->sex = "";
	this->age = 0;
}
// ����������� � �������������� ��������������
AnimalEntity::AnimalEntity(string sex, unsigned short int age) :
	sex(sex), age(age) {
}
// ����������� �����������
AnimalEntity::AnimalEntity(const AnimalEntity & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
}