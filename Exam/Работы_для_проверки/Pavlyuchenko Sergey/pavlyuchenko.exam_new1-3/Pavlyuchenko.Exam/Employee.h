// � ���� ����� ���������� ��������� ������� ������ Employee

#pragma once
#include "Libraries.h"
#include "AdressInfo.h"
#include "HumanEntity.h"
#include "Person.h"
#include "SalaryCalcTester.h"
#include "Functions.h"

// ����� Employee

class Employee : protected Person {
private:
	string position; // ���������
	unsigned short int account; // ��������� ����
	double salary; // ��������
	ISalaryCalculator* salaryCalc; // �������� ������� ��
	unsigned short int codePosition; // ��� ���������
	// �������
	void setSex(string sex);
	void setAge(unsigned short int age);
	void setName(string name);
	void setSurname(string surname);
	void setPhone(string phone);
	void setCity(string city);
	void setStreet(string street);
	void setHouse(unsigned short int house);
	void setFlat(unsigned short int flat);
	void setPosition(string position);
	void setAccount(unsigned short int account);
	void setSalary(double salary);
	void setCodePosition(unsigned short int codePosition);
	void setSalaryCalcRule(unsigned short int codePosition);
public:
	// ����������� �� ���������
	Employee();
	// ����������� � �������������� ��������������
	Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary);
	// ������������� ����������� � ������ ������� ��
	Employee(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat, string position, unsigned short int account, float salary, unsigned short int codePosition);
	// ����������� �����������
	Employee(const Employee &obj);
	// �������� ������������
	Employee operator=(const Employee &obj);
	// �������
	string getSex() const;
	unsigned short int getAge() const;
	string getName() const;
	string getSurname() const;
	string getPhone() const;
	string getCity() const;
	string getStreet() const;
	unsigned short int getHouse() const;
	unsigned short int getFlat() const;
	string getPosition() const;
	unsigned short int getAccount() const;
	double getSalary() const;
	unsigned short int getCodePosition() const;
	// ��������� ostream, istream
	friend ostream& operator<<(ostream& out, const Employee obj);
	friend istream& operator>>(istream& in, Employee &obj);
	// ����� ��� ����������� ������ �������� ��
	ISalaryCalculator* createSalaryCalcRule(int codePosition);
	// ����������
	~Employee();
};