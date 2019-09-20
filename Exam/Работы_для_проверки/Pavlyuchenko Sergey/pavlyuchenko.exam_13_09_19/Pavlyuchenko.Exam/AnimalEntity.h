// � ���� ����� ���������� ��������� ������� ������ AnimalEntity

#pragma once
#include "Lib.h"
#include "AdressInfo.h"

// ����� AnimalEntity

class AnimalEntity : public AdressInfo {
protected:
	string sex; // ���
	string age; // �������
public:
	// ����������� �� ���������
	AnimalEntity();
	// ����������� � �������������� ��������������
	AnimalEntity(string value1, string value2, unsigned short int value3, unsigned short int value4, string value5, string value6);
	// ����������� �����������
	AnimalEntity(const AnimalEntity &obj);
	// �������
	void setSex(string sex);
	void setAge(string age);
	// �������
	string getSex() const;
	string getAge() const;
	// ����������
	~AnimalEntity();
};
