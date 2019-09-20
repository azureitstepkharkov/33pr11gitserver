// В этом файле содержится реализация методов класса Employee

#include "Employee.h"

// Конструктор по умолчанию
Employee::Employee() {
	this->position = "";
	this->account = 0;
	this->salary = 0;
	this->salaryCalc = nullptr;
}
// Конструктор с использованием инициализатора
Employee::Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary) :
	Person(sex, age, name, surname, phone, city, street, house, flat), position(position), account(account), salary(salary) {
}
// Перегруженный конструктор с учетом расчета ЗП
Employee::Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary, unsigned short int codePosition) :
	Person(sex, age, name, surname, phone, city, street, house, flat), position(position), account(account), salary(salary), codePosition(codePosition) {
	this->salaryCalc = createSalaryCalcRule(codePosition);
}
// Конструктор копирования
Employee::Employee(const Employee & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
	this->codePosition = obj.codePosition;
	this->salaryCalc = obj.salaryCalc;
}
// Оператор присваивания
Employee Employee::operator=(const Employee & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->phone = obj.phone;
	this->city = obj.city;
	this->street = obj.street;
	this->house = obj.house;
	this->flat = obj.flat;
	this->position = obj.position;
	this->account = obj.account;
	this->salary = obj.salary;
	this->codePosition = obj.codePosition;
	this->salaryCalc = obj.salaryCalc;
	return *this;
}
// Сеттеры
void Employee::setSex(string sex) {
	this->sex = sex;
}
void Employee::setAge(unsigned short int age) {
	this->age = age;
}
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setSurname(string surname) {
	this->surname = surname;
}
void Employee::setPhone(string phone) {
	this->phone = phone;
}
void Employee::setCity(string city) {
	this->city = city;
}
void Employee::setStreet(string street) {
	this->street = street;
}
void Employee::setHouse(unsigned short int house) {
	this->house = house;
}
void Employee::setFlat(unsigned short int flat) {
	this->flat = flat;
}
void Employee::setPosition(string position) {
	this->position = position;
}
void Employee::setAccount(unsigned short int account) {
	this->account = account;
}
void Employee::setSalary(double salary) {
	this->salary = salary;
}
void Employee::setCodePosition(unsigned short int codePosition) {
	this->codePosition = codePosition;
}
void Employee::setSalaryCalcRule(unsigned short int codePosition) {
	this->salaryCalc = createSalaryCalcRule(codePosition);
}
// Геттеры
string Employee::getSex() const {
	return this->sex;
}
unsigned short int Employee::getAge() const {
	return this->age;
}
string Employee::getName() const {
	return this->name;
}
string Employee::getSurname() const {
	return this->surname;
}
string Employee::getPhone() const {
	return this->phone;
}
string Employee::getCity() const {
	return this->city;
}
string Employee::getStreet() const {
	return this->street;
}
unsigned short int Employee::getHouse() const {
	return this->house;
}
unsigned short int Employee::getFlat() const {
	return this->flat;
}
string Employee::getPosition() const {
	return this->position;
}
unsigned short int Employee::getAccount() const {
	return this->account;
}
double Employee::getSalary() const {
	return this->salary;
}
unsigned short int Employee::getCodePosition() const {
	return this->codePosition;
}
// Оператор ostream
ostream& operator<<(ostream &out, const Employee obj) {
	out << "Пол: " << obj.getSex() << endl;
	out << "Возраст: " << obj.getAge() << endl;
	out << "Имя: " << obj.getName() << endl;
	out << "Фамилия: " << obj.getSurname() << endl;
	out << "Телефон: " << obj.getPhone() << endl;
	out << "Город: " << obj.getCity() << endl;
	out << "Улица: " << obj.getStreet() << endl;
	out << "Номер дома: " << obj.getHouse() << endl;
	out << "Номер квартиры: " << obj.getFlat() << endl;
	out << "Должность: " << obj.getPosition() << endl;
	out << "Карточный счет: " << obj.getAccount() << endl;
	out << "Код должности: " << obj.getCodePosition() << endl;
	switch (obj.getCodePosition())	{
	case 1:
		out << "Правило расчета ЗП: Оклад" << endl;
		break;
	case 2:
		out << "Правило расчета ЗП: Оклад и премия" << endl;
		break;
	case 3:
		out << "Правило расчета ЗП: Оплата по часам" << endl;
		break;
	case 4:
		out << "Правило расчета ЗП: Оплата с % от выручки" << endl;
		break;
	default:
		out << "Правило расчета ЗП: Оклад" << endl;
		break;
	}
	out << "Зарплата: " << obj.getSalary() << endl;

	return out;
}
// Оператор istream
istream& operator>>(istream &in, Employee &obj) {
	system("color 07");
	in.get();
	obj.sex = checkSex(); // Пол
	obj.age = checkNumber(in, "Возраст: "); // Возраст
	obj.name = checkString(in, "Имя: "); // Имя
	obj.surname = checkString(in, "Фамилия: "); // Фамилия
	obj.phone = checkPhone(in); // Телефон
	obj.city = checkString(in, "Город: "); // Город
	obj.street = checkString(in, "Улица: "); // Улица
	obj.house = checkNumber(in, "Номер дома: "); // Номер дома
	obj.flat = checkNumber(in, "Номер квартиры: "); // Номер квартиры
	obj.position = checkPosition(in); // Должность
	obj.account = checkNumber(in, "Карточный счет: "); // Карточный счет
	obj.codePosition = checkCodePosition(in); // Код должности
	// Зарплата
	obj.salaryCalc = obj.createSalaryCalcRule(obj.codePosition);
	if (obj.salaryCalc == nullptr) {
		obj.salary = 0;
	}
	else {
		obj.salary = obj.salaryCalc->getSalary();
	}

	return in;
}
// Метод для определения правил подсчета ЗП
ISalaryCalculator* Employee::createSalaryCalcRule(int codePosition) {
	ISalaryCalculator* tempCalc = nullptr;
	double base;
	double bonus;
	double hour;
	double ratePerHour;
	double percent;
	double earnings;
	switch (codePosition) {
	case 1: 
		base = checkCalc(cin, "Введите оклад: ");
		tempCalc = new Rule1(base);
		break;
	case 2:
		base = checkCalc(cin, "Введите оклад: ");
		bonus = checkCalc(cin, "Введите премию: ");
		tempCalc = new Rule2(base, bonus);
		break;
	case 3: 
		hour = checkCalc(cin, "Введите количество часов: ");
		ratePerHour = checkCalc(cin, "Введите почасовую оплату: ");
		tempCalc = new Rule3(hour, ratePerHour);
		break;
	case 4: 
		base = checkCalc(cin, "Введите оклад: ");
		percent = checkCalc(cin, "Введите % от выручки: ");
		earnings = checkCalc(cin, "Введите выручку: ");
		tempCalc = new Rule4(base, percent, earnings);
		break;
	default: 
		tempCalc = new Rule1(base);
		break;
	}
	return tempCalc;
}
// Деструктор
Employee::~Employee() {
	// cout << "Employee object " << this << " deleted!" << endl;
	delete salaryCalc;
	// Закоментировано, чтобы не загромождать вывод
}

