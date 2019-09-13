// В этом файле содержатся прототипы методов класса Employee

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"

// Класс Employee

class Employee : public Person {
protected:
	string position; // Должность
	unsigned short int account; // Карточный счет
	float salary; // Зарплата
public:
	// Конструктор по умолчанию
	Employee();
	// Конструктор с использованием инициализатора
	Employee(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7, string value8, unsigned short int value9, float value10);
	// Конструктор копирования
	Employee(const Employee &obj);
	// Сеттеры
	void setPosition(string position);
	void setAccount(unsigned short int account);
	void setSalary(float salary);
	// Геттеры
	string getPosition() const;
	unsigned short int getAccount() const;
	float getSalary() const;
	// Операторы ostream, istream
	friend ostream& operator<<(ostream& out, const Employee &obj);
	friend istream& operator>>(istream& in, Employee &obj);
	// Деструктор
	~Employee();
};