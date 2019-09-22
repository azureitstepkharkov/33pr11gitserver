// � ���� ����� ���������� ��������� ������� ������ AnimalEntity

#pragma once
#include "Libraries.h"

// ����� AnimalEntity

class AnimalEntity {
protected:
	string sex; // ���
	unsigned short int age; // �������
	// ����������� �� ���������
	AnimalEntity();
	// ����������� � �������������� ��������������
	AnimalEntity(string sex, unsigned short int age);
	// ����������� �����������
	AnimalEntity(const AnimalEntity &obj);
	// ������ ����������� ����������
	virtual ~AnimalEntity() = 0 {};
};
