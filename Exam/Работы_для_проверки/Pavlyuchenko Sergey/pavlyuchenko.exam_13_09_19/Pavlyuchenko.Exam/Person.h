// � ���� ����� ���������� ��������� ������� ������ Person

#pragma once
#include "Lib.h"
#include "AdressInfo.h"
#include "HumanEntity.h"

// ����� Person

class Person : public HumanEntity {
protected:
	string phone; // �������
public:
	// ����������� �� ���������
	Person();
	// ����������� � �������������� ��������������
	Person(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6, string value7);
	// ����������� �����������
	Person(const Person &obj);
	// �������
	void setPhone(string phone);
	// �������
	string getPhone() const;
	// ����������
	~Person();
};