// � ���� ����� ���������� ���������� ������ AdressInfo

#include "AdressInfo.h"

// ����������� �� ���������
AdressInfo::AdressInfo() {
	this->city = "";
	this->street = "";
	this->house = 0;
	this->flat = 0;
}
// ����������� � �������������� ��������������
AdressInfo::AdressInfo(string city, string street, unsigned short int house, unsigned short int flat) :
	city(city), street(street), house(house), flat(flat) {
}