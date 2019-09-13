// В этом файле содержится функция Main

#include "Lib.h"
#include "AdressInfo.h"
#include "AnimalEntity.h"
#include "HumanEntity.h"
#include "Person.h"
#include "Employee.h"
#include "Department.h"

int main() {
	setlocale(0, "");

	// 1-2 Запрограммировать понятие "Cотрудник"
	Employee sergey("Харьков", "Гагарина", 2, 4, "Сергей", "Павлюченко", "+38(043)3123123", "Программист", 3213764212317654, 5647.55);

	// Закоментировано, чтобы не загромождать вывод
	// cout << "Employee >>:" << endl;
	// cin >> sergey;
	// cout << "Employee <<:" << endl;
	// cout << sergey;

	// 1-2 Запрограммировать понятие "Отдел"
	Department store;
	store.setDepartmentName("33PR11");
	store.setBossName("Сергей");
	store.addToEmployeeList(sergey);
	cout << "Department <<:" << endl;
	cout << store;


	return 0;
}