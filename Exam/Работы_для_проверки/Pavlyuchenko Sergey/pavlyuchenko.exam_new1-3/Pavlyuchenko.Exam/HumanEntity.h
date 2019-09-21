// В этом файле содержатся прототипы методов класса HumanEntity

#pragma once
#include "Libraries.h"
#include "AnimalEntity.h"

// Класс HumanEntity

class HumanEntity : protected AnimalEntity {
protected:
	string name; // Имя
	string surname; // Фамилия
	// Конструктор по умолчанию
	HumanEntity();
	// Конструктор с использованием инициализатора
	HumanEntity(string sex, unsigned short int age, string name, string surname);
	// Конструктор копирования
	HumanEntity(const HumanEntity &obj);
	// Деструктор
	~HumanEntity();
};