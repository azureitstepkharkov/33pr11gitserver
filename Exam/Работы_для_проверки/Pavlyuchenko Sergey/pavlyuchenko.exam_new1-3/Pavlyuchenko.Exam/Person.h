// � ���� ����� ���������� ��������� ������� ������ Person

#pragma once
#include "Libraries.h"
#include "AdressInfo.h"
#include "HumanEntity.h"

// ����� Person

class Person : protected HumanEntity, protected AdressInfo {
protected:
	string phone; // �������
	// ����������� �� ���������
	Person();
	// ����������� � �������������� ��������������
	Person(string sex, unsigned short int age, string name, string surname, string phone, string city, string street, unsigned short int house, unsigned short int flat);
	// ����������� �����������
	Person(const Person &obj);
	// ������ ����������� ����������
	virtual ~Person() = 0 {};
};