#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>
#include "AnimalEntity.h"
#include "HumanEntity.h"
#include  "Person.h"
#include  "Employee.h"
#include  "AddressInfo.h"
#include "Department.h"


using namespace std;





int main()
{
	Person* p = new Person("Иван", "Иванов", "+38097998877", "Prospect Nauki 40");
	//*/
	p->print();
	//cout << p << endl;//operator << 
						//operator []

	delete p;
	system("pause");
}


