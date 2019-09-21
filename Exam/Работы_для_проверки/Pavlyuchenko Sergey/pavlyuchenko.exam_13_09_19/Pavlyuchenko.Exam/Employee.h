// � ���� ����� ���������� ��������� ������� ������ Employee

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"

// ����� Employee

class Employee : public Person {
protected:
	string position; // ���������
	unsigned short int account; // ��������� ����
	float salary; // ��������
public:
	// ����������� �� ���������
	Employee();
	// ����������� � �������������� ��������������
	Employee(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7, string value8, unsigned short int value9, float value10);
	// ����������� �����������
	Employee(const Employee &obj);
	// �������
	void setPosition(string position);
	void setAccount(unsigned short int account);
	void setSalary(float salary);
	// �������
	string getPosition() const;
	unsigned short int getAccount() const;
	float getSalary() const;
	// ��������� ostream, istream
	friend ostream& operator<<(ostream& out, const Employee &obj);
	friend istream& operator>>(istream& in, Employee &obj);
	// ����������
	~Employee();
};