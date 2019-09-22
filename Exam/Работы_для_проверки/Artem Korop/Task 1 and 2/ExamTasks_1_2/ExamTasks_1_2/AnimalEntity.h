#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <list>

using namespace std;

class AnimalEntity
{
protected:
	bool sex;
	int age;

private:

	AnimalEntity(AnimalEntity& obj)
	{
		cout << "call Constructor Copy AnimalEntity" << endl;
	}

public:

	AnimalEntity(int age, bool sex)
	{
		this->age = age;
		this->sex = sex;
	}
	
	// Destuctor
	~AnimalEntity()
	{
		cout << "call Destructor AnimalEntity()" << endl;
	}
	
	// ������
	bool getSex()
	{
		return this->sex;
	}
	
	// ������
	int getAge()
	{
		return this->age;
	}

	// ������
	void setSex(bool sex)
	{
		this->sex = sex;
	}

	// ������
	void setAge(int age)
	{
		this->age = age;
	}
	
	// ����� � �������
	void print()
	{
		cout << this->sex << ", " << this->age << ";" << endl;
	}
	
	// �������� ���������� ��������� <<
	friend ostream&	operator << (ostream& os, const AnimalEntity& c);
};

//���������� ��������� <<
ostream& operator<<(ostream& os, const AnimalEntity& animal)
{
	os << animal.sex << ", " << animal.age << endl;

	return os;
}