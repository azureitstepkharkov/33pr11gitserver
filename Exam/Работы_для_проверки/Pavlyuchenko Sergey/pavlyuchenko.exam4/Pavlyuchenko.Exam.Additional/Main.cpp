// В этом файле содержится функция Main

#include "Libraries.h"
#include "List.h"
#include "Array.h"
#include "IteratorTest.h"

int main() {
	// Подключение русского языка при вводе-выводе
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List<ListNode<string>> list1;
	cout << "String list:" << endl;

	list1.push(new ListNode<string>("January"));
	list1.push(new ListNode<string>("February"));
	list1.push(new ListNode<string>("March"));
	list1.push(new ListNode<string>("April"));
	list1.push(new ListNode<string>("May"));
	list1.push(new ListNode<string>("June"));
	list1.push(new ListNode<string>("July"));
	list1.push(new ListNode<string>("August"));
	list1.push(new ListNode<string>("September"));
	list1.push(new ListNode<string>("October"));
	list1.push(new ListNode<string>("November"));
	list1.push(new ListNode<string>("December"));

	cout << list1;
	cout << "List1 size: " << list1.getSize() << endl << endl;

	// Array<const char*> arr;
	// arr.push("Pavlyuchenko");
	// arr.push("Sergiy");
	// arr.push("Viktorovich");
	// arr.print();
	cout << "Array: ";
	Array<int> arr;
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.push(4);
	arr.push(5);
	arr.push(6);

	cout << arr << endl;
	cout << "Array size: " << arr.getSize() << endl;

	IteratorList<string> iterator(list1);

	return 0;
}