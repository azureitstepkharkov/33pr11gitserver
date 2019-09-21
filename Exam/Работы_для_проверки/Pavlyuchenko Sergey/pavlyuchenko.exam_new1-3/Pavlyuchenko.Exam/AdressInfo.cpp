// В этом файле содержится реализация класса AdressInfo

#include "AdressInfo.h"

// Конструктор по умолчанию
AdressInfo::AdressInfo() {
	this->city = "";
	this->street = "";
	this->house = 0;
	this->flat = 0;
}
// Конструктор с использованием инициализатора
AdressInfo::AdressInfo(string city, string street, unsigned short int house, unsigned short int flat) :
	city(city), street(street), house(house), flat(flat) {
}