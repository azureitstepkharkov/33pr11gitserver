// В этом файле содержится прототипы методов класса Department

#include "Department.h"

// Конструктор по умолчанию
Department::Department() {
	this->departmentName = "";
	this->bossName = "";
}
// Конструктор с использованием инициализатора
Department::Department(string departmentName, std::list<Employee> employees, string bossName) :
	departmentName(departmentName), employees(employees), bossName(bossName) {
}
// Конструктор копирования
Department::Department(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
}
// Сеттеры
void Department::setDepartmentName(string departmentName) {
	this->departmentName = departmentName;
}
void Department::setListEmployees(std::list<Employee> employees) {
	this->employees = employees;
}
void Department::setBossName(string bossName) {
	this->bossName = bossName;
}
// Геттеры
string Department::getDepartmentName() const {
	return this->departmentName;
}
std::list<Employee> Department::getListEmployees() const {
	return this->employees;
}
string Department::getBossName() const {
	return this->bossName;
}
// Добавить элемент в список
void Department::addToEmployeeList(Employee &obj) {
	employees.push_back(obj);
}
// Оператор ostream
ostream & operator<<(ostream & out, const Department & obj) {
	out << "Название отдела: " << obj.getDepartmentName() << endl;
	out << "Имя начальника: " << obj.getBossName() << endl;
	out << "Сотрудники:" << endl;
	for (Employee val : obj.employees) {
		out << val;
	}

	return out;
}
// Деструктор
Department::~Department() {
	// cout << "Department object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
}
