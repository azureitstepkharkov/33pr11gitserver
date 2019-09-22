// В этом файле содержатся прототипы методов класса HumanEntity

#pragma once
#include "Lib.h"
#include "AdressInfo.h"

// Класс HumanEntity

class HumanEntity : public AdressInfo {
protected:
	string name; // Имя
	string surname; // Фамилия
public:
	// Конструктор по умолчанию
	HumanEntity();
	// Конструктор с использованием инициализатора
	HumanEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6);
	// Конструктор копирования
	HumanEntity(const HumanEntity &obj);
	// Сеттеры
	void setName(string name);
	void setSurname(string surname);
	// Геттеры
	string getName() const;
	string getSurname() const;
	// Деструктор
	~HumanEntity();
};