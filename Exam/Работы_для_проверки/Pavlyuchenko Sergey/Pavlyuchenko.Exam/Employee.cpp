// В этом файле содержится прототипы методов класса Employee

#include "Employee.h"

// Конструктор по умолчанию
Employee::Employee() {
	this->position = "";
	this->account = 0;
	this->salary = 0;
}
// Конструктор с использованием инициализатора
Employee::Employee(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7, string value8, unsigned short int value9, float value10) :
	Person(value1, value2, value3, value4, value5, value6, value7), position(value8), account(value9), salary(value10) {
}
// Конструктор копирования
Employee::Employee(const Employee & obj) {
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
}
// Сеттеры
void Employee::setPosition(string position) {
	this->position = position;
}
void Employee::setAccount(unsigned short int account) {
	this->account = account;
}
void Employee::setSalary(float salary) {
	this->salary = salary;
}
// Геттеры
string Employee::getPosition() const {
	return this->position;
}
unsigned short int Employee::getAccount() const {
	return this->account;
}
float Employee::getSalary() const {
	return this->salary;
}
// Оператор ostream
ostream& operator<<(ostream &out, const Employee &obj) {
	out << "Город: " << obj.getCity() << endl;
	out << "Улица: " << obj.getStreet() << endl;
	out << "Дом: " << obj.getHouse() << endl;
	out << "Квартира: " << obj.getFlat() << endl;
	out << "Имя: " << obj.getName() << endl;
	out << "Фамилия: " << obj.getSurname() << endl;
	out << "Телефон: " << obj.getPhone() << endl;
	out << "Должность: " << obj.getPosition() << endl;
	out << "Карточный счет: " << obj.getAccount() << endl;
	out << "Зарплата: " << obj.getSalary() << endl;

	return out;
}
// Оператор istream
istream& operator>>(istream &in, Employee &obj) {
	cout << "Город: ";
	in >> obj.city;
	cout << "Улица: ";
	in >> obj.street;
	cout << "Дом: ";
	in >> obj.house;
	cout << "Квартира: ";
	in >> obj.flat;
	cout << "Имя: ";
	in >> obj.name;
	cout << "Фамилия: ";
	in >> obj.surname;
	cout << "Телефон: ";
	in >> obj.phone;
	cout << "Должность: ";
	in >> obj.position;
	cout << "Карточный счет: ";
	in >> obj.account;
	cout << "Зарплата: ";
	in >> obj.salary;

	return in;
}
// Деструктор
Employee::~Employee() {
	// cout << "Employee object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
}

