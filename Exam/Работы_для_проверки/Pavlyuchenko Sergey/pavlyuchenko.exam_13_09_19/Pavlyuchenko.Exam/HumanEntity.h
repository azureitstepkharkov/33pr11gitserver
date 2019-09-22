// � ���� ����� ���������� ��������� ������� ������ HumanEntity

#pragma once
#include "Lib.h"
#include "AdressInfo.h"

// ����� HumanEntity

class HumanEntity : public AdressInfo {
protected:
	string name; // ���
	string surname; // �������
public:
	// ����������� �� ���������
	HumanEntity();
	// ����������� � �������������� ��������������
	HumanEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6);
	// ����������� �����������
	HumanEntity(const HumanEntity &obj);
	// �������
	void setName(string name);
	void setSurname(string surname);
	// �������
	string getName() const;
	string getSurname() const;
	// ����������
	~HumanEntity();
};