// � ���� ����� ���������� ������� Main

#include "Libraries.h"
#include "Employee.h"
#include "Department.h"
#include "Menu.h"

int main() {
	// ����������� �������� ����� ��� �����-������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	

	// ��� ������	
	/*Employee sergey("�������", 33, "������", "����������", "+38(043)3123123", "�������", "��������", 2, 4, "�����������", 3213764212317654, 5647.55);
	Employee petr("�������", 45, "����", "��������", "+38(032)3443253", "�������", "��������", 4, 1, "�������", 4563248387659876, 2312.45);
	//cin >> sergey;
	cout << sergey;
	cout << petr;

	Department store;
	list<Employee> employees;
	employees.push_back(sergey);
	employees.push_back(petr);
	store.setDepartmentName("33PR11");
	store.setBossName("������");
	store.setListEmployees(employees);
	cout << "Department <<:" << endl;
	cout << store;*/

	// ���� ������� ������ true - ���������
	if (menu()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n���������� ���������...\n";
		Sleep(2000);
	}

	//vector<Employee*> employees; // ��������� Employee
	/*for (int i = 0; i < 2; i++)
	{
		Employee* newEmployee = new Employee();
		cout << "\n������� ���������� #" << employees.size() + 1 << endl;
		cin >> newEmployee;
		employees.push_back(newEmployee);
	}*/
	/*int i = 0;
	for (Employee* val : employees) {
		i++;
		cout << "��������� #" << i << endl;
		cout << val;
		cout << endl;
	}
	for (int i = 2; i < 3; i++)
	{
		Employee* newEmployee = new Employee();
		cout << "\n������� ���������� #" << employees.size() + 1 << endl;
		cin >> newEmployee;
		employees.push_back(newEmployee);
	}*/

	return 0;
}