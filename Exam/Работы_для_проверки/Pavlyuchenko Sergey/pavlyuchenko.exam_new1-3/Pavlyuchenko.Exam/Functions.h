// В этом заголовочном файле содержатся прототипы функций для работы с проектом

#include "Libraries.h"

#include<ios> 
#include<limits> 

// Прототипы

void clearInput(); // Очистка ввода
string checkSex(); // Проверка правильности выбора пола
int checkNumber(istream &in, string description); // Проверка правильности ввода числа
double checkCalc(istream &in, string description); // Проверка правильности ввода данных калькулятора
string checkString(istream &in, string description); // Проверка правильности ввода строки
string checkPhone(istream &in); // Проверка правильности ввода телефона
string checkPosition(istream &in); // Проверка правильности ввода должности
int checkCodePosition(istream &in); // Проверка правильности ввода должности