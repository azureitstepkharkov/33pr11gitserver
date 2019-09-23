// В этом файле содержится класс Stack и его наследники

#include "Libraries.h"

// Stack

class Stack {
protected:
	Stack* Body;//внутренняя реализация - тело: или массив или список
public:
	// virtual void Push(int) = 0;
	// virtual int Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

// Реализация через массив
template<class T>
class ArrayStack : public Stack {
public: // Конструкторы
	ArrayStack(int size) {
		arrTest = new T[size];
		top = -1;
		capacity = size;
	}
	~ArrayStack() {
		delete arrTest;
	}
public: // Методы
	void push(T newitem) {
		if (isFull()) {
			cout << "Стек перегружен!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Добавляем" << newitem << endl;
		arrTest[++top] = newitem;
	}
	T pop() {
		if (isEmpty()) {
			cout << "Стек пуст!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Удаляем" << peek() << endl;
		return arrTest[top--];
	}
	T peek() {
		if (!isEmpty()) {
			return arrTest[top];
		}
		else {
			exit(EXIT_FAILURE);
		}
	}
	bool isEmpty() override {
		return getSize() == 0;
	}
	int getSize() {
		return top + 1;
	}
	bool isFull() override {
		return top == capacity - 1;
	}
private:
	T* arrTest; // Массив
	int top; // Верхний элемент
	int capacity; // Вместимость стека
};

// Реализация через список
template<class T>
class ListStack : public Stack {
public: // Конструкторы
	ListStack(int size, List<T> &obj) {
		list = obj;
		capacity = size;
	}
	~ListStack() {};
public: // Методы
	void push(T newitem) {
		if (isFull()) {
			cout << "Стек перегружен!" << endl;
			exit(EXIT_FAILURE);
		}
		else {
			cout << "Добавляем" << endl;
			list.push_back(newitem);
		}
	}
	T pop() {
		if (isEmpty()) {
			cout << "Стек пуст!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Удаляем" << endl;
		return list.pop();
	}
	bool isEmpty() override {
		return list.empty();
	};
	virtual bool isFull() {
		return list.getSize() == capacity - 1;
	};
private:
	List<T> list;
	int capacity; // Вместимость стека
};