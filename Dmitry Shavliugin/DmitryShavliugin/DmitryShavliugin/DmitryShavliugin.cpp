#include "pch.h"
//#include <iostream>
//-----------------------------------------------------------------
//#include"AdressInfo.h"
//#include"AnimalEntity.h"

//using namespace std;

int main()
{
	cout << "\n\n-------------------------------------First------------------------------------------\n\n";

	AdressInfo Dima("Kharkiv", "Jakira street", 8, 12);								//First
	cout << Dima <<endl;

	cout << "\n\n-------------------------------------Second-----------------------------------------\n\n";

	AnimalEntity Dog("male", 6);													//Second
	cout << Dog << endl;

	cout << "\n\n-------------------------------------Third------------------------------------------\n\n";

	HumanEntity Dmitry("Dmitry", "Shavliugin");
	cout << Dmitry << endl;

	cout << "\n\n-------------------------------------Fourth-----------------------------------------\n\n";

	Person Shavliugin("066-916-5144", &Dima);
	cout << Shavliugin << endl;

	cout << "\n\n-------------------------------------Fifth------------------------------------------\n\n";

	Employee DmitryShavliugin("C++ Developer", 5556487, 1000);
	cout << DmitryShavliugin << endl;

	cout << "\n\n-------------------------------------Sixth------------------------------------------\n\n";



	return 0;
}