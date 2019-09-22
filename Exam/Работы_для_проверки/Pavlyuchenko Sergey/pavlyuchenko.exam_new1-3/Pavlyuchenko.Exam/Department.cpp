// � ���� ����� ���������� ���������� ������� ������ Department

#include "Department.h"

// ����������� �� ���������
Department::Department() {
	this->departmentName = "";
	this->bossName = "";
}
// ����������� � �������������� ��������������
Department::Department(string departmentName, list<Employee> employees, string bossName) :
	departmentName(departmentName), employees(employees), bossName(bossName) {
}
// ����������� �����������
Department::Department(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
}
// �������� ������������
Department Department::operator=(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
	return *this;
}
// �������
void Department::setDepartmentName(string departmentName) {
	this->departmentName = departmentName;
}
void Department::setListEmployees(list<Employee> employees) {
	this->employees = employees;
}
void Department::setBossName(string bossName) {
	this->bossName = bossName;
}
// �������
string Department::getDepartmentName() const {
	return this->departmentName;
}
list<Employee> Department::getListEmployees() const {
	return this->employees;
}
string Department::getBossName() const {
	return this->bossName;
}
// �������� ������� � ������
void Department::addToEmployeeList(Employee &obj) {
	employees.push_back(obj);
}
// �������� ostream
ostream & operator<<(ostream & out, const Department obj) {
	out << "�������� ������: " << obj.getDepartmentName() << endl;
	out << "��� ����������: " << obj.getBossName() << endl;
	cout << endl;
	int i = 0;
	for (Employee val : obj.employees) {
		i++;
		out << "��������� #" << i << endl;
		out << val;
		cout << endl;
	}

	return out;
}
// �������� istream
istream& operator>>(istream &in, Department &obj) {
	system("color 07");
	obj.departmentName = checkString(in, "�������� ������: "); // �������� ������
	obj.bossName = checkString(in, "��� ����������: "); // ��� ����������
	// ���� �����������
	cout << endl;
	short int employeesQuantity = checkNumber(in, "������� ���������� �����������: ");
	cout << endl;
	for (int i = 0; i < employeesQuantity; i++) {
		Employee* newEmployee = new Employee();
		cout << "��������� #" << i + 1 << endl;
		in >> *newEmployee;
		obj.employees.push_back(*newEmployee);
		cout << endl;
	}

	return in;
}
// ����������
Department::~Department() {
	// cout << "Department object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
	employees.clear();
}
