#include "stdafx.h"
#include "Department.h"




Department::~Department()
{
}

//Department::Department(string depname, string pos, string acc, string salary, string phone, string ct, string tpstrt, string strt, string hsnum, unsigned int apart, string name, string surname, string sex, unsigned int age)
//{
//	this->DepartmentName = depname;
//	//this->EmployeesList = new Employee("designer", "5148755423119142", "12000 UAN", "+380994597228", "Kharkov", "street","Sumskaya", "45a", 84, "Aleksandr", "Petrov", "male", 23);
//	//this->Cheif = new HumanEntity("Maksim", "Andreenko", "male", 35);
//}

ostream & operator<<(ostream & out_data, Department & data)
{
	out_data << data.DepartmentName << " " << data.EmployeesList << " " << data.Cheif
		<< endl;
	return out_data;
}