// � ���� ����� ���������� ��������� ������� ������ Department

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"
#include "Employee.h"

// ����� Department

class Department {
private:
	string departmentName; // �������� ������
	std::list<Employee> employees; // ������ �����������
	string bossName; // ��� ����������
public:
	// ����������� �� ���������
	Department();
	// ������������� �����������
	Department(string departmentName, std::list<Employee> employees, string bossName);
	// ����������� �����������
	Department(const Department &obj);
	// �������
	void setDepartmentName(string departmentName);
	void setListEmployees(std::list<Employee> employees);
	void setBossName(string bossName);
	// �������
	string getDepartmentName() const;
	std::list<Employee> getListEmployees() const;
	string getBossName() const;
	// �������� ������� � ������
	void addToEmployeeList(Employee &obj);
	// �������� istream
	friend ostream& operator<<(ostream& out, const Department &obj);
	// ����������
	~Department();
};