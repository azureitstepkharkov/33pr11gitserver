// � ���� ����� ���������� ���������� �������, ��������� � ����

#include "Libraries.h"

bool menu() {
	vector<Employee*> employees; // ��������� Employee
	vector<Department*> departments; // ��������� Department

	string menuItems[5] = {
		"\t�������� ���������� � ���������",
		"\t����� ��������� �����������",
		"\t���� ������",
		"\t����� ������",
		"\t�����"
	};
	short int pointer = 0; // ������� �� ������� ����
	while (true) {
		system("cls");
		// ����� �������� ������� ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "\n�������:" << endl << endl;
		for (int i = 0; i < (sizeof(menuItems) / sizeof(*menuItems)); i++)	{
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << menuItems[i] << endl;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menuItems[i] << endl;
			}
		}
		// �������� ��������� ������ � �������� ����
		while (true) {
			// ����������� ����� � ������� GetAsyncKeyState
			if (GetAsyncKeyState(VK_UP) != 0) {
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			// ����������� ���� � ������� GetAsyncKeyState
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				pointer += 1;
				if (pointer == (sizeof(menuItems) / sizeof(*menuItems)))
				{
					pointer = 0;
				}
				break;
			}
			// ����� ������ ���� � ������� GetAsyncKeyState
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer) {
				case 0: // ���� ����������(��)
					try {
						Employee* newEmployee = new Employee();
						cout << "\n������� ���������� #" << employees.size() + 1 << endl; 
						cin >> *newEmployee;
						employees.push_back(newEmployee);
					}
					catch (const exception& ex) {
						cout << ex.what() << endl;
						cout << "\n�� ���������� ������� ����������!" << endl;
					}
					Sleep(2000);
					break;
				case 1: // ����� ����������(��)
					if (employees.empty()) { // ���� ��������� ����� - ��������������
						system("color 47");
						cout << "\n������ �� ��������� ��� ���������!\n";
						Sleep(1000);
						system("color 07");
					}
					else { // ����� ��������� ���� ������
						try {
							/*cout << endl;
							int i = 0;
							for (Employee* val : employees) {
								i++;
								cout << "��������� #" << i << endl;
								cout << val;
								cout << endl << flush;
							}*/

							vector<Employee*>::iterator ptr; 
							cout << endl;
							int i = 0;
							for (ptr = employees.begin(); ptr < employees.end(); ptr++) {
								i++;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
								cout << "��������� #" << i << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << *(*ptr) << endl << flush;
							}
						}
						catch (const exception& ex) {
							cout << "\n������: " << ex.what() << endl;
							cout << "�� ���������� ����� ����������!" << endl;
						}
						Sleep(5000);
					}
					break;
				case 2: // ���� ������(��)
					try {
						Department* newDepartment = new Department();
						cout << "\n������� ����� #" << departments.size() + 1 << endl;
						cin.get();
						cin >> *newDepartment;
						departments.push_back(newDepartment);
					}
					catch (const exception& ex) {
						cout << ex.what() << endl;
						cout << "\n�� ���������� ������� �����!" << endl;
					}
					Sleep(2000);
					break; 
				case 3: // ����� ������(��)
					if (departments.empty()) { // ���� ��������� ����� - ��������������
						system("color 47");
						cout << "\n������ �� ��������� ��� ���������!\n";
						Sleep(1000);
						system("color 07");
					}
					else { // ����� ��������� ���� ������
						try {
							int i = 0;
							for (Department* val : departments) {
								i++;
								cout << "����� #" << i << endl;
								cout << val;
								cout << endl;
							}
						}
						catch (const exception& ex) {
							cout << ex.what() << endl;
							cout << "\n�� ���������� ����� �����!" << endl;
						}
						Sleep(5000);
					}
					break;
				case 4: // ����� �� ���������
					employees.clear();
					departments.clear();
					return true;
					break;
				default:

					break;
				}
				break;
			}
		}
		Sleep(150);
	}
	return false;
}
