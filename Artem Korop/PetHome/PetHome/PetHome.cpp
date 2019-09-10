// PetHome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:
	int age;
	int sex;
public:
	virtual double doEat();
	virtual double doSound();
};

class Pet : public Animal
{
	string nick;
	Pet() {}
public: 
	Pet(string nick, int age, int sex)
	{
		this->nick = nick;
		this->age = age;
		this->sex = 1;
	}
};

class Fish : public Pet
{
protected:
	string eat = "Worms";
	string sound = "No Sound";
public:
	Fish() { this->eat; }
	Fish(string eat) {this->eat = eat;}
	Fish() { this->sound}
	Fish(string sound) { this->sound = sound; }

	virtual double doEat()
	{
		cout << eat << endl;
	}

	virtual double doSound()
	{
		cout << sound << endl;
	}
};

class Bird : public Pet
{
protected:
	string eat = "Bread";
	string sound = "Kar-Kar";
public:
	Bird() { this->eat }
	Bird(string eat) { this->eat = eat; }
	Bird() { this->sound }
	Fish(string sound) { this->sound = sound; }
	virtual string doEat()
	{
		cout << eat << endl;
	}
	virtual double doSound()
	{
		cout << sound << endl;
	}
};
class Dog : public Pet
{
protected:
	string eat = "Meat";
	string sound = "Gav-Gav-Gav";
public:
	Dog() { this->eat }
	Dog(string eat) { this->eat = eat; }
	Dog() { this->sound }
	Dog(string sound) { this->sound = sound; }

	virtual double doEat()
	{
		cout << eat << endl;
	}
	virtual double doSound()
	{
		cout << sound << endl;
	}
};
	friend ostream& operator<< (ostream& os, Animal data )
	{
		os << " " << data.doEat  << data.doSound
		  << endl;
		return os;
	}

};


int main()
{
	system("pause");
    return 0;
}

