// � ���� ����� ���������� ��������� ������� ������ AdressInfo

#pragma once
#include "Lib.h"

// ����� AdressInfo

class AdressInfo {
protected:
	string city; // ��������
	string street; // ����
	unsigned short int house; // ���
	unsigned short int flat; // ��������
public:
	// ����������� �� ���������
	AdressInfo();
	// ����������� � �������������� ��������������
	AdressInfo(string, string, unsigned short int, unsigned short int);
	// �������
	void setCity(string city);
	void setStreet(string street);
	void setHouse(unsigned short int house);
	void setFlat(unsigned short int flat);
	// �������
	string getCity() const;
	string getStreet() const;
	unsigned short int getHouse() const;
	unsigned short int getFlat() const;
	// ������ ����������� ����������
	virtual ~AdressInfo() = 0 {};
};