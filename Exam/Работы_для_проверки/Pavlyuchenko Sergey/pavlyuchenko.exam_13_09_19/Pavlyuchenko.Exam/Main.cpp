// � ���� ����� ���������� ������� Main

#include "Lib.h"
#include "AdressInfo.h"
#include "AnimalEntity.h"
#include "HumanEntity.h"
#include "Person.h"
#include "Employee.h"
#include "Department.h"

int main() {
	setlocale(0, "");

	// 1-2 ����������������� ������� "C��������"
	Employee sergey("�������", "��������", 2, 4, "������", "����������", "+38(043)3123123", "�����������", 3213764212317654, 5647.55);

	// ���������������, ����� �� ������������ �����
	// cout << "Employee >>:" << endl;
	// cin >> sergey;
	// cout << "Employee <<:" << endl;
	// cout << sergey;

	// 1-2 ����������������� ������� "�����"
	Department store;
	store.setDepartmentName("33PR11");
	store.setBossName("������");
	store.addToEmployeeList(sergey);
	cout << "Department <<:" << endl;
	cout << store;


	return 0;
}