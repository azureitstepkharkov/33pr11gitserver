// В этом файле содержатся прототипы методов класса Person

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"

// Класс Person

class Person : public HumanEntity {
protected:
	string phone; // Телефон
public:
	// Конструктор по умолчанию
	Person();
	// Конструктор с использованием инициализатора
	Person(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7);
	// Конструктор копирования
	Person(const Person &obj);
	// Сеттеры
	void setPhone(string phone);
	// Геттеры
	string getPhone() const;
	// Деструктор
	~Person();
};