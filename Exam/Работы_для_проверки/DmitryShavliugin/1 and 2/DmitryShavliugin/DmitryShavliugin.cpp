#include "pch.h"
//#include <iostream>
//-----------------------------------------------------------------
//#include"AdressInfo.h"
//#include"AnimalEntity.h"

//using namespace std;

int main()
{
	/*cout << "\n\n--------------------------------------------------------------------------\n\n";

	AdressInfo DmitryAdress("Kharkiv", "Jakira street", 8, 12);								//First
	cout << DmitryAdress <<endl;

	cout << "\n\n------------------------------------------------------------------------\n\n";

	AnimalEntity Dog("male", 6);													//Second
	cout << Dog << endl;

	cout << "\n\n-------------------------------------------------------------------------\n\n";

	HumanEntity Dmitry("Dmitry", "Shavliugin");
	cout << Dmitry << endl;

	cout << "\n\n------------------------------------------------------------------------------\n\n";

	Person Shavliugin("066-916-5144", &DmitryAdress);
	cout << Shavliugin << endl;

	cout << "\n\n----------------------------------------------------------------------------\n\n";

	Employee DmitryShavliugin("C++ Developer", 5556487, 1000);
	cout << DmitryShavliugin << endl;

	cout << "\n\n--------------------------------------------------------------------------\n\n";

	Department ItStep("Software Development", "Ivan Ivanov");
	cout << ItStep << endl;*/
	







	//----------------------------------------------------------------------------------------------

//First Name, Second Name, Sex, Age, Number, Position, Bank Account, Salary, City, Street, House Number, Apartment Number
	list<Employee*> employeeList;
	Employee* DmitryShavliugin = new Employee("Dmitry", "Shavliugin", "male", 19, "+380669165144", 
												"C++ Developer", 5556487, 2745.15,
												"Kharkiv", "Jakira Street", 8, 12);

	//employeeList.push_back(DmitryShavliugin);

	return 0;
}