// � ���� ����� ���������� ����� Stack � ��� ����������

#include "Libraries.h"

// Stack

class Stack {
protected:
	Stack* Body;//���������� ���������� - ����: ��� ������ ��� ������
public:
	// virtual void Push(int) = 0;
	// virtual int Pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
};

// ���������� ����� ������
template<class T>
class ArrayStack : public Stack {
public: // ������������
	ArrayStack(int size) {
		arrTest = new T[size];
		top = -1;
		capacity = size;
	}
	~ArrayStack() {
		delete arrTest;
	}
public: // ������
	void push(T newitem) {
		if (isFull()) {
			cout << "���� ����������!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "���������" << newitem << endl;
		arrTest[++top] = newitem;
	}
	T pop() {
		if (isEmpty()) {
			cout << "���� ����!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "�������" << peek() << endl;
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
	T* arrTest; // ������
	int top; // ������� �������
	int capacity; // ����������� �����
};

// ���������� ����� ������
template<class T>
class ListStack : public Stack {
public: // ������������
	ListStack(int size, List<T> &obj) {
		list = obj;
		capacity = size;
	}
	~ListStack() {};
public: // ������
	void push(T newitem) {
		if (isFull()) {
			cout << "���� ����������!" << endl;
			exit(EXIT_FAILURE);
		}
		else {
			cout << "���������" << endl;
			list.push_back(newitem);
		}
	}
	T pop() {
		if (isEmpty()) {
			cout << "���� ����!" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "�������" << endl;
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
	int capacity; // ����������� �����
};