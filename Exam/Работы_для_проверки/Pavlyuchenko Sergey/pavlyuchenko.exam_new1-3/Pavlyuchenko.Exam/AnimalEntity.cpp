// В этом файле содержится реализация класса AnimalEntity

#include "AnimalEntity.h"

// Конструктор по умолчанию
AnimalEntity::AnimalEntity() {
	this->sex = "";
	this->age = 0;
}
// Конструктор с использованием инициализатора
AnimalEntity::AnimalEntity(string sex, unsigned short int age) :
	sex(sex), age(age) {
}
// Конструктор копирования
AnimalEntity::AnimalEntity(const AnimalEntity & obj) {
	this->sex = obj.sex;
	this->age = obj.age;
}