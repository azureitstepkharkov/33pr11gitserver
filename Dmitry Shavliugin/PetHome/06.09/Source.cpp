#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
	//string sex;
	//int age;
	virtual void doEat() = 0;
	virtual void doSound() = 0;
	/*Animal(string sex, int age) {
		sex = sex;
		age = age;
	}*/
};

class Fish :public Animal {
public:
	void doEat() override {
		cout << "Водоросли" << endl;
	}
	void doSound() override {
		cout << "No Sound" << endl;
	}
};

class Bird :public Animal {
public:
	void doEat() override {
		cout << "Зерно" << endl;
	}
	void doSound() override {
		cout << "Bird sound.." << endl;
	}
};

class Dog :public Animal {
public:
	void doEat() override {
		cout << "Мясо" << endl;
	}
	void doSound() override {
		cout << "Bark-Bark-Bark!" << endl;
	}
};

class PetHome {
public:
	void doSound(Animal* animal) {
		animal->doSound();
	}
};

void main() {
	Bird* Rodger = new Bird;
	Fish* Nail = new Fish;
	Dog* Mike = new Dog;

	PetHome pethome;
	pethome.doSound(Mike);
	system("pause");
}