// ExamWorkZhaboLidia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<fstream>
#include"AnimalEntity.h"
#include"HumanEntity.h"
#include"Person.h"
using namespace std;


int main()
{
	AdressInfo PetyaDom();
	Person Petya("135446+87", "Kharkov", "Nayki", "12a", "4", "Vasya", "Petrov", 25, 1);
	cout << Petya;
	system("pause");
    return 0;
}

