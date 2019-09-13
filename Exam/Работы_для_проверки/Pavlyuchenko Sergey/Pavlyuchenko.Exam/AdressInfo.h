// В этом файле содержатся прототипы методов класса AdressInfo

#pragma once
#include "Lib.h"

// Класс AdressInfo

class AdressInfo {
protected:
	string city; // Название
	string street; // Цвет
	unsigned short int house; // Дом
	unsigned short int flat; // Квартира
public:
	// Конструктор по умолчанию
	AdressInfo();
	// Конструктор с использованием инициализатора
	AdressInfo(string, string, unsigned short int, unsigned short int);
	// Сеттеры
	void setCity(string city);
	void setStreet(string street);
	void setHouse(unsigned short int house);
	void setFlat(unsigned short int flat);
	// Геттеры
	string getCity() const;
	string getStreet() const;
	unsigned short int getHouse() const;
	unsigned short int getFlat() const;
	// Чистый виртуальный деструктор
	virtual ~AdressInfo() = 0 {};
};