// ExamWorkZhaboLidia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<fstream>
#include"AnimalEntity.h"
#include"HumanEntity.h"
#include"Person.h"
#include"Employee.h"
#include"Department.h"
using namespace std;


int main()
{
	/*AdressInfo PetyaDom();
	Person Petya("135446+87", "Kharkov", "Nayki", "12a", "4", "Vasya", "Petrov", 25, 1);
	cout << Petya;*/
	
	vector<Employee*> MEN;
	Employee* m1 = new Employee("Lidia", "Zhabo", "developer", 1500,"5151 5151 5151 5151");
	Employee* m2 = new Employee("Petr", "Petrov", "QA", 45, 15, "4141 4141 4141 4141");
	Employee* m3 = new Employee("Ivan","Ivanov","system admin",700,"3111 3131 3111 3131");
	MEN.push_back(m1);
	MEN.push_back(m2);
	MEN.push_back(m3);
	
	for (int i = 0; i < MEN.size(); i++)
	{
		cout << *MEN[i] << endl;
		//для списка так не выйде, потому что нет индексатора
		//а для вектора индексатор реализован
	}

	cout << "++++++++++++++iterator+++++++++++++" << endl;
	vector<Employee*>::iterator ptr;
	for (ptr = MEN.begin(); ptr < MEN.end(); ptr++)
	{
		cout << *(*ptr) << endl;
	}
	
	/*Employee *boss = new  Employee ("BOSS", "BOSS", "admin", 17700, "3111 3131 3111 3131");

	Department *dep  =  new Department("Development Dep.", boss, MEN);

	cout << *dep;*/
	system("pause");
    return 0;
}

