// PetHome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<assert.h>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
using namespace std;
class Animal
{
public:
	int sex;
	int age;
	virtual void doEat() = 0;
	virtual void doSound() = 0;
};
class Pet : public Animal
{
protected:
	string nick;
};
class Bird : public Pet
{
private:
	Bird() {}
	Bird(const Bird & obj) {}
public:
	Bird(string nick, int sex, int age)
	{
		this->age = age;
		this->sex = sex;
		this->nick = nick;
	}
	virtual void doEat() 
	{
		cout << " eats corn" << endl;
	}
	virtual void doSound()
	{
		cout << "chirik" << endl;
	}
};
class Fish : public Pet
{
private:
	Fish() {}
	Fish(const Fish & obj) {}
public:
	Fish(string nick, int sex, int age)
	{
		this->age = age;
		this->sex = sex;
		this->nick = nick;
	}
	virtual void doEat()
	{
		cout << " eats seaweed" << endl;
	}
	virtual void doSound()
	{
		cout << " no sound " << endl;
	}
};
class Dog : public Pet
{
private:
	Dog() {}
	Dog(const Dog & obj) {}
public:
	Dog(string nick, int sex, int age)
	{
		this->age = age;
		this->sex = sex;
		this->nick = nick;
	}
	virtual void doEat()
	{
		cout << " eats meat" << endl;
	}
	virtual void doSound()
	{
		cout << "bark- bark!" << endl;
	}
};

int main()
{
	Bird* Rodger = new Bird("Rodger",1,2);
	Fish* Nail = new Fish("Nail", 1, 2);
	Dog* Mike = new Dog("Mike", 1, 2);

	delete Rodger;
	delete Nail;
	delete Mike;

	system("pause");
    return 0;
}

