// PetHome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка
using namespace std;

class Animal
{
protected:
	int age;
	int sex;
	virtual int doEat() = 0;
	virtual int doSound() = 0;
public:
	
	
};
class Fish : public Animal
{
public :

};
class Bird : public Animal
{

};
class Dog : public Animal
{

};

int main()
{
    return 0;
}

