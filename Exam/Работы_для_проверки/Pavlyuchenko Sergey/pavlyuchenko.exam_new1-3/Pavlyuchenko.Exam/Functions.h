// � ���� ������������ ����� ���������� ��������� ������� ��� ������ � ��������

#include "Libraries.h"

#include<ios> 
#include<limits> 

// ���������

void clearInput(); // ������� �����
string checkSex(); // �������� ������������ ������ ����
int checkNumber(istream &in, string description); // �������� ������������ ����� �����
double checkCalc(istream &in, string description); // �������� ������������ ����� ������ ������������
string checkString(istream &in, string description); // �������� ������������ ����� ������
string checkPhone(istream &in); // �������� ������������ ����� ��������
string checkPosition(istream &in); // �������� ������������ ����� ���������
int checkCodePosition(istream &in); // �������� ������������ ����� ���������