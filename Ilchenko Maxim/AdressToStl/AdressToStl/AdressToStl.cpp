// AdressToStl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны для сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка

#include "City.h"
#include "TypeStreet.h"
#include "Street.h"
#include "Adress.h"

using namespace std;

/*
bool operator < (City a, City b)
{
	return a.cityName < b.cityName;
}
*/
int main()
{
	std::cout << "Hello World!\n";

	//Adress adress1("City", "avenu", "Street", "3a");


	system("pause");
	return 0;
}

//Требования к "моему" классу, чтобы класс был "удобным" членом коллекции stl:
	/*
	1. Безопасный конструктор по умолчанию (умеет создавать корректный объект)
	часто protected
	2. Закрытый копирующий конструктор,
	чтобы передавать объект класс только по ссылке или через указатель
	3. оператор вывода <<

	ВАЖНО: только, если не используем полиморфизм
	4. оператор < для версии sort по умолчанию из stl
	5. оператор () для версии sort с шаблонным параметром
	Если используем полиморфизм, то сортировка в версии
	sort(MEN.begin(), MEN.end(), mycomparergreater);
	метод вывода и заполнения - в версии с параметром
	Employee*
	*/
return 0;
}



