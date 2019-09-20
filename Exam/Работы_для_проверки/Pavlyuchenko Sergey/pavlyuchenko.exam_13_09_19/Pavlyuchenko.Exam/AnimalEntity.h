// В этом файле содержатся прототипы методов класса AnimalEntity

#pragma once
#include "Lib.h"
#include "AdressInfo.h"

// Класс AnimalEntity

class AnimalEntity : public AdressInfo {
protected:
	string sex; // Пол
	string age; // Возраст
public:
	// Конструктор по умолчанию
	AnimalEntity();
	// Конструктор с использованием инициализатора
	AnimalEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6);
	// Конструктор копирования
	AnimalEntity(const AnimalEntity &obj);
	// Сеттеры
	void setSex(string sex);
	void setAge(string age);
	// Геттеры
	string getSex() const;
	string getAge() const;
	// Деструктор
	~AnimalEntity();
};
