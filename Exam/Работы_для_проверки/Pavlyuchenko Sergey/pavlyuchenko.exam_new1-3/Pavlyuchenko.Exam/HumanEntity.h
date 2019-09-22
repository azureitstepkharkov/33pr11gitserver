// � ���� ����� ���������� ��������� ������� ������ HumanEntity

#pragma once
#include "Libraries.h"
#include "AnimalEntity.h"

// ����� HumanEntity

class HumanEntity : protected AnimalEntity {
protected:
	string name; // ���
	string surname; // �������
	// ����������� �� ���������
	HumanEntity();
	// ����������� � �������������� ��������������
	HumanEntity(string sex, unsigned short int age, string name, string surname);
	// ����������� �����������
	HumanEntity(const HumanEntity &obj);
	// ����������
	~HumanEntity();
};