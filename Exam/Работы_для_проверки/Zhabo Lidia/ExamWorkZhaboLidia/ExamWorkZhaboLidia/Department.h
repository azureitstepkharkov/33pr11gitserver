#pragma once
#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include"Employee.h"
using namespace std; 

class Department
{
private:
	string Name;
	list <Employee*> collective;
	Employee boss;
	Department() {};
public:
	
	~Department() {};
};

