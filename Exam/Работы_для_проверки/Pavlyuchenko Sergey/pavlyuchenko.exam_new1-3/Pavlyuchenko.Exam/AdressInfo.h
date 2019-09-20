// � ���� ����� ���������� ��������� ������� ������ AdressInfo

#pragma once
#include "Libraries.h"

// ����� AdressInfo

class AdressInfo {
protected:
	string city; // ��������
	string street; // ����
	unsigned short int house; // ���
	unsigned short int flat; // ��������
	// ����������� �� ���������
	AdressInfo();
	// ����������� � �������������� ��������������
	AdressInfo(string city, string street, unsigned short int house, unsigned short int flat);
	// ������ ����������� ����������
	virtual ~AdressInfo() = 0 {};
};