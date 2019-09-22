// В этом файле содержатся прототипы методов класса AdressInfo

#pragma once
#include "Libraries.h"

// Класс AdressInfo

class AdressInfo {
protected:
	string city; // Название
	string street; // Цвет
	unsigned short int house; // Дом
	unsigned short int flat; // Квартира
	// Конструктор по умолчанию
	AdressInfo();
	// Конструктор с использованием инициализатора
	AdressInfo(string city, string street, unsigned short int house, unsigned short int flat);
	// Чистый виртуальный деструктор
	virtual ~AdressInfo() = 0 {};
};