// В этом файле содержится реализация методов класса Department

#include "Department.h"

// Конструктор по умолчанию
Department::Department() {
	this->departmentName = "";
	this->bossName = "";
}
// Конструктор с использованием инициализатора
Department::Department(string departmentName, list<Employee> employees, string bossName) :
	departmentName(departmentName), employees(employees), bossName(bossName) {
}
// Конструктор копирования
Department::Department(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
}
// Оператор присваивания
Department Department::operator=(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
	return *this;
}
// Сеттеры
void Department::setDepartmentName(string departmentName) {
	this->departmentName = departmentName;
}
void Department::setListEmployees(list<Employee> employees) {
	this->employees = employees;
}
void Department::setBossName(string bossName) {
	this->bossName = bossName;
}
// Геттеры
string Department::getDepartmentName() const {
	return this->departmentName;
}
list<Employee> Department::getListEmployees() const {
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
ostream & operator<<(ostream & out, const Department obj) {
	out << "Название отдела: " << obj.getDepartmentName() << endl;
	out << "Имя начальника: " << obj.getBossName() << endl;
	cout << endl;
	int i = 0;
	for (Employee val : obj.employees) {
		i++;
		out << "Сотрудник #" << i << endl;
		out << val;
		cout << endl;
	}

	return out;
}
// Оператор istream
istream& operator>>(istream &in, Department &obj) {
	system("color 07");
	obj.departmentName = checkString(in, "Название отдела: "); // Название отдела
	obj.bossName = checkString(in, "Имя начальника: "); // Имя начальника
	// Ввод сотрудников
	cout << endl;
	short int employeesQuantity = checkNumber(in, "Введите количество сотрудников: ");
	cout << endl;
	for (int i = 0; i < employeesQuantity; i++) {
		Employee* newEmployee = new Employee();
		cout << "Сотрудник #" << i + 1 << endl;
		in >> *newEmployee;
		obj.employees.push_back(*newEmployee);
		cout << endl;
	}

	return in;
}
// Деструктор
Department::~Department() {
	// cout << "Department object " << this << " deleted!" << endl;
	// Закоментировано, чтобы не загромождать вывод
	employees.clear();
}
