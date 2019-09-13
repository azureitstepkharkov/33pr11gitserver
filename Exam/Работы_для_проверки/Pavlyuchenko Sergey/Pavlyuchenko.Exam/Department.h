// В этом файле содержатся прототипы методов класса Department

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"
#include "Employee.h"

// Класс Department

class Department {
private:
	string departmentName; // Название отдела
	std::list<Employee> employees; // Список сотрудников
	string bossName; // Имя начальника
public:
	// Конструктор по умолчанию
	Department();
	// Перегруженный конструктор
	Department(string departmentName, std::list<Employee> employees, string bossName);
	// Конструктор копирования
	Department(const Department &obj);
	// Сеттеры
	void setDepartmentName(string departmentName);
	void setListEmployees(std::list<Employee> employees);
	void setBossName(string bossName);
	// Геттеры
	string getDepartmentName() const;
	std::list<Employee> getListEmployees() const;
	string getBossName() const;
	// Добавить элемент в список
	void addToEmployeeList(Employee &obj);
	// Оператор istream
	friend ostream& operator<<(ostream& out, const Department &obj);
	// Деструктор
	~Department();
};