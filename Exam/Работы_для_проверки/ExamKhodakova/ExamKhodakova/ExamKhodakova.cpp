// ExamKhodakova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include"Person.h"

#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>
using namespace std;


int main()
{
	cout << "My Exam!!!\n";

	Person a("+380994597228","", "Kharkiv", "street", "Sumskaya", "45a", 84, "Aleksandr", "Petrov", 1, 23);

	cout << a;
}

