#include "pch.h"
#include "Department.h"


Department::Department(string NameDepartment, string ListEmployees, string Head_of_Department)
{
	this->NameDepartment = NameDepartment;
//	this->ListEmployees = ListEmployees;
	this->Head_of_Department = Head_of_Department;
}
Department::~Department()
{
}
