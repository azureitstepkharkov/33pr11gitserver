// В этом файле содержится функция Main

#include "Libraries.h"
#include "List.h"
#include "Array.h"
#include "StackTest.h"

int main() {
	// Подключение русского языка при вводе-выводе
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Блоки 1-3

	// Int list
	List<int> list1;
	for (int j = 0; j < 10; ++j) {
		list1.push_back(j + 1);
	}
	//cout << "Int list: " << list1 << endl;
	cout << "Int list: ";
	for (List<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	List<string> list2;
	list2.push_back("January");
	list2.push_back("February");
	list2.push_back("March");
	list2.push_back("April");
	list2.push_back("May");
	list2.push_back("June");
	list2.push_back("July");
	list2.push_back("August");
	list2.push_back("September");
	list2.push_back("October");
	list2.push_back("November");
	list2.push_back("December");
	//cout << "String list: " << list2 << endl;
	cout << "String list: ";
	cout << "[Начало]" << ' ';
	for (List<string>::iterator it = list2.begin(); it != list2.end(); ++it) {
		cout << *it << ' ';
		if (it.hasNext()) {
			cout << "[Дальше - пустота]" << ' ';
		}
	}
	cout << "[Конец]" << ' ' << endl;

	Array<const char*> arr1;
	arr1.push("Pavlyuchenko");
	arr1.push("Sergiy");
	arr1.push("Viktorovich");
	cout << "Const char* array: ";
	for (Array<const char*>::iterator it = arr1.begin(); it != arr1.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	// Блок 4
	Array<int> arr2;
	arr2.push(1);
	arr2.push(2);
	arr2.push(3);
	arr2.push(4);
	arr2.push(5);
	arr2.push(6);
	ArrayStack<int> s1(2);
	for (int i = 0; i < arr2.getSize(); i++) {
		s1.push(arr2[i]);
	}

	/*List<char> list3;
	list3.push_back('A');
	list3.push_back('B');
	list3.push_back('C');
	list3.push_back('D');
	list3.push_back('E');
	list3.push_back('F');
	list3.push_back('G');
	list3.push_back('H');
	ListStack<char> s2(2, list3);
	for (List<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
		s2.push(*it);
	}*/	

	return 0;
}