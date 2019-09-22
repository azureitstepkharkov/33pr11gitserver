// В этом файле содержится прототипы методов класса Person

#include "Person.h"

// Конструктор по умолчанию
Person::Person() {
	this->phone = "";
}
// Конструктор с использованием инициализатора
Person::Person(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7) :
	HumanEntity(value1, value2, value3, value4, value5, value6), phone(value7) {
}
// Конструктор копирования
Person::Person(const Person & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
}
// Сеттеры
void Person::setPhone(string phone) {
	this->phone = phone;
}
// Геттеры
string Person::getPhone() const {
	return this->phone;
}
// Деструктор
Person::~Person() {
	// cout << "Person object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
}

