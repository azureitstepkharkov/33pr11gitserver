// В этом файле содержится функция Main

#include "Libraries.h"
#include "Employee.h"
#include "Department.h"
#include "Menu.h"

int main() {
	// Подключение русского языка при вводе-выводе
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	

	// Для тестов	
	/*Employee sergey("Мужчина", 33, "Сергей", "Павлюченко", "+38(043)3123123", "Харьков", "Гагарина", 2, 4, "Программист", 3213764212317654, 5647.55);
	Employee petr("Мужчина", 45, "Петр", "Петрович", "+38(032)3443253", "Харьков", "Гагарина", 4, 1, "Дворник", 4563248387659876, 2312.45);
	//cin >> sergey;
	cout << sergey;
	cout << petr;

	Department store;
	list<Employee> employees;
	employees.push_back(sergey);
	employees.push_back(petr);
	store.setDepartmentName("33PR11");
	store.setBossName("Сергей");
	store.setListEmployees(employees);
	cout << "Department <<:" << endl;
	cout << store;*/

	// Если функция вернет true - завершаем
	if (menu()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\nЗавершение программы...\n";
		Sleep(2000);
	}

	//vector<Employee*> employees; // Коллекция Employee
	/*for (int i = 0; i < 2; i++)
	{
		Employee* newEmployee = new Employee();
		cout << "\nВведите сотрудника #" << employees.size() + 1 << endl;
		cin >> newEmployee;
		employees.push_back(newEmployee);
	}*/
	/*int i = 0;
	for (Employee* val : employees) {
		i++;
		cout << "Сотрудник #" << i << endl;
		cout << val;
		cout << endl;
	}
	for (int i = 2; i < 3; i++)
	{
		Employee* newEmployee = new Employee();
		cout << "\nВведите сотрудника #" << employees.size() + 1 << endl;
		cin >> newEmployee;
		employees.push_back(newEmployee);
	}*/

	return 0;
}