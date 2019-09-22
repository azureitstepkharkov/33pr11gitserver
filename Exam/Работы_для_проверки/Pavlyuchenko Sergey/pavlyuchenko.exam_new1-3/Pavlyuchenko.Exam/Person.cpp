// В этом файле содержится реализация методов класса Person

#include "Person.h"

// Конструктор по умолчанию
Person::Person() {
	this->phone = "";
}
// Конструктор с использованием инициализатора
Person::Person(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat) :
	HumanEntity(sex, age, name, surname), phone(phone), AdressInfo(city, street, house, flat) {
}
// Конструктор копирования
Person::Person(const Person & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
}