#pragma once
#include <string>
using namespace std;
class AnimalEntity
{
protected:
	int sex;
	int age;
private:
	//AnimalEntity() {};
	AnimalEntity(const AnimalEntity& obj) {};
public:


	AnimalEntity() {};
	AnimalEntity(int sex, int age);
	friend ostream& operator<<(ostream& os, AnimalEntity info)
	{
		os << " Sex: " << info.sex
			<< " Age: " << info.age 
			<< endl;
		return os;
	}
	~AnimalEntity();
};

