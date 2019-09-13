// � ���� ����� ���������� ��������� ������� ������ Department

#include "Department.h"

// ����������� �� ���������
Department::Department() {
	this->departmentName = "";
	this->bossName = "";
}
// ����������� � �������������� ��������������
Department::Department(string departmentName, std::list<Employee> employees, string bossName) :
	departmentName(departmentName), employees(employees), bossName(bossName) {
}
// ����������� �����������
Department::Department(const Department & obj) {
	this->departmentName = obj.departmentName;
	this->employees = obj.employees;
	this->bossName = obj.bossName;
}
// �������
void Department::setDepartmentName(string departmentName) {
	this->departmentName = departmentName;
}
void Department::setListEmployees(std::list<Employee> employees) {
	this->employees = employees;
}
void Department::setBossName(string bossName) {
	this->bossName = bossName;
}
// �������
string Department::getDepartmentName() const {
	return this->departmentName;
}
std::list<Employee> Department::getListEmployees() const {
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
ostream & operator<<(ostream & out, const Department & obj) {
	out << "�������� ������: " << obj.getDepartmentName() << endl;
	out << "��� ����������: " << obj.getBossName() << endl;
	out << "����������:" << endl;
	for (Employee val : obj.employees) {
		out << val;
	}

	return out;
}
// ����������
Department::~Department() {
	// cout << "Department object " << this << " deleted!" << endl;
	// ���������������, ����� �� ������������ �����
}
