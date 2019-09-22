#pragma once
#include<string>

using namespace std;

class AnimalEntity
{

	protected:
		bool sex;//1- мужчина 0 женщина
		unsigned int age;

		AnimalEntity() {};
		AnimalEntity(AnimalEntity& anim) {};
	public:
		AnimalEntity(bool sex, unsigned int age);
	

		friend ostream& operator<<(ostream& out_data, AnimalEntity& anim);
		

		void setSex(bool sex) { this->sex = sex; }
		void setAge(unsigned int age) { this->age = age; }

		bool getSex() { return this->sex; }
		unsigned int getAge() { return this->age; }

		~AnimalEntity();
};

