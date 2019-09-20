// В этом файле содержится реализация класса HumanEntity

#include "HumanEntity.h"

// Конструктор по умолчанию
HumanEntity::HumanEntity() {
	this->name = "";
	this->surname = "";
}
// Конструктор с использованием инициализатора
HumanEntity::HumanEntity(string sex, unsigned short int age, string name, string surname) :
	AnimalEntity(sex, age), name(name), surname(surname) {
}
// Конструктор копирования
HumanEntity::HumanEntity(const HumanEntity & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
}
// Деструктор
HumanEntity::~HumanEntity() {
	// cout << "HumanEntity object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
}

