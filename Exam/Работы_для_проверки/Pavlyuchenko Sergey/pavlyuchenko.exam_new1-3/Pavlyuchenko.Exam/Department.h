// � ���� ����� ���������� ��������� ������� ������ Department

#pragma once
#include "Libraries.h"
#include "Functions.h"
#include "Employee.h"

// ����� Department

class Department {
private:
	string departmentName; // �������� ������
	list<Employee> employees; // ������ �����������
	string bossName; // ��� ����������
public:
	// ����������� �� ���������
	Department();
	// ������������� �����������
	Department(string departmentName, list<Employee> employees, string bossName);
	// ����������� �����������
	Department(const Department &obj);
	// �������� ������������
	Department operator=(const Department &obj);
	// �������
	void setDepartmentName(string departmentName);
	void setListEmployees(list<Employee> employees);
	void setBossName(string bossName);
	// �������
	string getDepartmentName() const;
	list<Employee> getListEmployees() const;
	string getBossName() const;
	// �������� ������� � ������
	void addToEmployeeList(Employee &obj);
	// ��������� ostream, istream
	friend ostream& operator<<(ostream& out, const Department obj);
	friend istream& operator>>(istream& in, Department &obj);
	// ����������
	~Department();
};