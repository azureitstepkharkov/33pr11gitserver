#pragma once
class Animal
{
protected:
	bool sex;
	int age;
	virtual void doEat()=0;
	virtual void doSound()=0;
public:
	bool getSex() { return sex; }
	void setSex(bool s) { sex = s; }
	int getAge() { return age; }
	void setAge(int a) { age = a; }
	Animal(bool s, int a ) { sex = s; age = a; };
	Animal() { sex = true; age = 0; };
	~Animal() {};
};

