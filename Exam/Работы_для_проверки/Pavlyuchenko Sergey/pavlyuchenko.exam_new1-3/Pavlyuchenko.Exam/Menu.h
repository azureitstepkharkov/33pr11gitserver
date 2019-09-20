// В этом файле содержится реализация функций, связанных с меню

#include "Libraries.h"

bool menu() {
	vector<Employee*> employees; // Коллекция Employee
	vector<Department*> departments; // Коллекция Department

	string menuItems[5] = {
		"\tДобавить сотрудника в коллекцию",
		"\tВывод коллекции сотрудников",
		"\tВвод отдела",
		"\tВывод отдела",
		"\tВыход"
	};
	short int pointer = 0; // Итертор по пунктам меню
	while (true) {
		system("cls");
		// Вывод названий пунктов меню
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "\nЗадания:" << endl << endl;
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
		// Создание механизма работы с пунктами меню
		while (true) {
			// Перемещение вверх с помощью GetAsyncKeyState
			if (GetAsyncKeyState(VK_UP) != 0) {
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			// Перемещение вниз с помощью GetAsyncKeyState
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				pointer += 1;
				if (pointer == (sizeof(menuItems) / sizeof(*menuItems)))
				{
					pointer = 0;
				}
				break;
			}
			// Выбор пункта меню с помощью GetAsyncKeyState
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer) {
				case 0: // Ввод сотрудника(ов)
					try {
						Employee* newEmployee = new Employee();
						cout << "\nВведите сотрудника #" << employees.size() + 1 << endl; 
						cin >> *newEmployee;
						employees.push_back(newEmployee);
					}
					catch (const exception& ex) {
						cout << ex.what() << endl;
						cout << "\nНе получается создать сотрудника!" << endl;
					}
					Sleep(2000);
					break;
				case 1: // Вывод сотрудника(ов)
					if (employees.empty()) { // Если коллекция пуста - предупреждение
						system("color 47");
						cout << "\nДанные не добавлены или загружены!\n";
						Sleep(1000);
						system("color 07");
					}
					else { // Иначе запускаем цикл вывода
						try {
							/*cout << endl;
							int i = 0;
							for (Employee* val : employees) {
								i++;
								cout << "Сотрудник #" << i << endl;
								cout << val;
								cout << endl << flush;
							}*/

							vector<Employee*>::iterator ptr; 
							cout << endl;
							int i = 0;
							for (ptr = employees.begin(); ptr < employees.end(); ptr++) {
								i++;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
								cout << "Сотрудник #" << i << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << *(*ptr) << endl << flush;
							}
						}
						catch (const exception& ex) {
							cout << "\nОшибка: " << ex.what() << endl;
							cout << "Не получается найти сотрудника!" << endl;
						}
						Sleep(5000);
					}
					break;
				case 2: // Ввод отдела(ов)
					try {
						Department* newDepartment = new Department();
						cout << "\nВведите отдел #" << departments.size() + 1 << endl;
						cin.get();
						cin >> *newDepartment;
						departments.push_back(newDepartment);
					}
					catch (const exception& ex) {
						cout << ex.what() << endl;
						cout << "\nНе получается создать отдел!" << endl;
					}
					Sleep(2000);
					break; 
				case 3: // Вывод отдела(ов)
					if (departments.empty()) { // Если коллекция пуста - предупреждение
						system("color 47");
						cout << "\nДанные не добавлены или загружены!\n";
						Sleep(1000);
						system("color 07");
					}
					else { // Иначе запускаем цикл вывода
						try {
							int i = 0;
							for (Department* val : departments) {
								i++;
								cout << "Отдел #" << i << endl;
								cout << val;
								cout << endl;
							}
						}
						catch (const exception& ex) {
							cout << ex.what() << endl;
							cout << "\nНе получается найти отдел!" << endl;
						}
						Sleep(5000);
					}
					break;
				case 4: // Выход из программы
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
