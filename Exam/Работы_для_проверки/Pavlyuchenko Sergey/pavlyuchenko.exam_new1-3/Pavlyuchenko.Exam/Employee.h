// В этом файле содержатся прототипы методов класса Employee

#pragma once
#include "Libraries.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"
#include "SalaryCalcTester.h"
#include "Functions.h"

// Класс Employee

class Employee : protected Person {
private:
	string position; // Должность
	unsigned short int account; // Карточный счет
	double salary; // Зарплата
	ISalaryCalculator* salaryCalc; // Механизм расчета ЗП
	unsigned short int codePosition; // Код должности
	// Сеттеры
	void setSex(string sex);
	void setAge(unsigned short int age);
	void setName(string name);
	void setSurname(string surname);
	void setPhone(string phone);
	void setCity(string city);
	void setStreet(string street);
	void setHouse(unsigned short int house);
	void setFlat(unsigned short int flat);
	void setPosition(string position);
	void setAccount(unsigned short int account);
	void setSalary(double salary);
	void setCodePosition(unsigned short int codePosition);
	void setSalaryCalcRule(unsigned short int codePosition);
public:
	// Конструктор по умолчанию
	Employee();
	// Конструктор с использованием инициализатора
	Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary);
	// Перегруженный конструктор с учетом расчета ЗП
	Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary, unsigned short int codePosition);
	// Конструктор копирования
	Employee(const Employee &obj);
	// Оператор присваивания
	Employee operator=(const Employee &obj);
	// Геттеры
	string getSex() const;
	unsigned short int getAge() const;
	string getName() const;
	string getSurname() const;
	string getPhone() const;
	string getCity() const;
	string getStreet() const;
	unsigned short int getHouse() const;
	unsigned short int getFlat() const;
	string getPosition() const;
	unsigned short int getAccount() const;
	double getSalary() const;
	unsigned short int getCodePosition() const;
	// Операторы ostream, istream
	friend ostream& operator<<(ostream& out, const Employee obj);
	friend istream& operator>>(istream& in, Employee &obj);
	// Метод для определения правил подсчета ЗП
	ISalaryCalculator* createSalaryCalcRule(int codePosition);
	// Деструктор
	~Employee();
};