// В этом файле содержится прототипы методов класса AnimalEntity

#pragma once
#include "Libraries.h"

// Класс AnimalEntity

class AnimalEntity {
protected:
	string sex; // Пол
	unsigned short int age; // Возраст
	// Конструктор по умолчанию
	AnimalEntity();
	// Конструктор с использованием инициализатора
	AnimalEntity(string sex, unsigned short int age);
	// Конструктор копирования
	AnimalEntity(const AnimalEntity &obj);
	// Чистый виртуальный деструктор
	virtual ~AnimalEntity() = 0 {};
};
