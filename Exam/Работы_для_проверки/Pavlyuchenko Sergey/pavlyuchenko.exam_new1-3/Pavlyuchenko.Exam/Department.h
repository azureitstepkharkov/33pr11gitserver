// В этом файле содержатся прототипы методов класса Department

#pragma once
#include "Libraries.h"
#include "Functions.h"
#include "Employee.h"

// Класс Department

class Department {
private:
	string departmentName; // Название отдела
	list<Employee> employees; // Список сотрудников
	string bossName; // Имя начальника
public:
	// Конструктор по умолчанию
	Department();
	// Перегруженный конструктор
	Department(string departmentName, list<Employee> employees, string bossName);
	// Конструктор копирования
	Department(const Department &obj);
	// Оператор присваивания
	Department operator=(const Department &obj);
	// Сеттеры
	void setDepartmentName(string departmentName);
	void setListEmployees(list<Employee> employees);
	void setBossName(string bossName);
	// Геттеры
	string getDepartmentName() const;
	list<Employee> getListEmployees() const;
	string getBossName() const;
	// Добавить элемент в список
	void addToEmployeeList(Employee &obj);
	// Операторы ostream, istream
	friend ostream& operator<<(ostream& out, const Department obj);
	friend istream& operator>>(istream& in, Department &obj);
	// Деструктор
	~Department();
};