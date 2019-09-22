// В этом файле содержатся прототипы методов класса Person

#pragma once
#include "Libraries.h"
#include "AdressInfo.h"
#include "HumanEntity.h"

// Класс Person

class Person : protected HumanEntity, protected AdressInfo {
protected:
	string phone; // Телефон
	// Конструктор по умолчанию
	Person();
	// Конструктор с использованием инициализатора
	Person(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat);
	// Конструктор копирования
	Person(const Person &obj);
	// Чистый виртуальный деструктор
	virtual ~Person() = 0 {};
};