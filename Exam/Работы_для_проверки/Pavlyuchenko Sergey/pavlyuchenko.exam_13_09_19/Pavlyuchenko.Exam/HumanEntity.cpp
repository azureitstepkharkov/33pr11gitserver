// В этом файле содержится реализация класса HumanEntity

#include "HumanEntity.h"

// Конструктор по умолчанию
HumanEntity::HumanEntity() {
	this->name = "";
	this->surname = "";
}
// Конструктор с использованием инициализатора
HumanEntity::HumanEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6) :
	AdressInfo(value1, value2, value3, value4), name(value5), surname(value6) {
}
// Конструктор копирования
HumanEntity::HumanEntity(const HumanEntity & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
}
// Сеттеры
void HumanEntity::setName(string name) {
	this->name = name;
}
void HumanEntity::setSurname(string surname) {
	this->surname = surname;
}
// Геттеры
string HumanEntity::getName() const {
	return this->name;
}
string HumanEntity::getSurname() const {
	return this->surname;
}
// Деструктор
HumanEntity::~HumanEntity() {
	// cout << "HumanEntity object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
}

