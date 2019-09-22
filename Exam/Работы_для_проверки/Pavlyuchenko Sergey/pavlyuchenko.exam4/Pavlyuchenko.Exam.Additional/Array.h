// В этом файле содержатся реализация класса Array

#include "Libraries.h"

class Element;
template <class T>
class Array {
private:
	template <class T>
	class Element {
	public:
		T value;
		Element *next;
		Element *prev;
		// Конструкторы
		Element() {
			value = 0;
			next = nullptr;
			prev = nullptr;
		};
		Element(T value, Element *next, Element *prev) {
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
		Element(T value) {
			this->value = value;
			this->next = nullptr;
			this->prev = nullptr;
		}
		// Сеттеры
		void setValue(T value) {
			this->value = value;
		}
		void setNext(Element *next) {
			this->next = next;
		}
		void setPrev(Element *prev) {
			this->prev = next;
		}
		// Геттеры
		T getValue() {
			return this->value;
		}
		Element *getNext() {
			return this->next;
		}
		Element *getPrev() {
			return this->prev;
		}
	};
	int size;
	Element<T> *head;
	Element<T> *tail;
public:
	// Конструкторы
	Array();
	Array(const Array &other);
	// // Операторы
	T & operator[](const int index);
	friend ostream& operator<<(ostream& out, Array obj) {
		for (int i = 0; i < obj.getSize(); i++) {
			out << obj[i] << ' ';
		}

		return out;
	}
	Array operator+(const Array other);
	Array & operator=(const Array &other);	
	// Методы 
	int getSize();
	void add(T value);
	int getUpperBound() { return size - 1; }
	T getAt(int index);
	void setAt(T value, int index);
	Element<T> *getData() { return head; }
	void insertAt(T value, int index);
	void removeAt(int index);
	void push(T value);
	void del();
	// Деструктор
	~Array();
};
// Конструктор:
template<class T>
Array<T>::Array() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<class T>
Array<T>::Array(const Array & other) {
	// std::cout << "Объект создан: " << this << std::endl;
	this->head = nullptr;
	this->size = 0;
	Element<T> *temp = other.head;
	while (temp) {
		this->push(temp->getValue());
		temp = temp->getNext();
	}
}
// Операторы
template<class T>
T & Array<T>::Array::operator[](const int index) {
	int counter = 0;
	Element<T> *current = this->head;
	while (current) {
		if (counter == index) {
			return current->value;
		}
		current = current->next;
		counter++;
	}
}
template<class T>
Array<T> Array<T>::operator+(const Array other) {
	Array<T> temp;
	Element<T> *j = other.head;
	for (Element<T> *i = this->head; i != nullptr && j != nullptr; i = i->getNext()) {
		temp.push(i->getValue() + j->getValue());
		j = j->getNext();
	}
	return temp;
}
template<class T>
Array<T> & Array<T>::operator=(const Array & other) {
	// std::cout << "Объект создан: " << this << std::endl;
	Element<T> *temp = other.head;
	while (temp) {
		this->push(temp->getValue());
		temp = temp->getNext();
	}
	return *this;
}

// Реализация методов:

template<class T>
void Array<T>::push(T value) {
	Element<T> *temp = new Element<T>(value);
	if (head) {
		temp->setPrev(tail);
		tail->setNext(temp);
		tail = temp;
	}
	else {
		temp->setPrev(nullptr);
		head = tail = temp;
	}
	size++;
}
template<class T>
void Array<T>::del() {
	if (head) {
		Element<T> *tmp = head;
		Element<T> *current = tail;
		current = head;
		tmp = head->next;
		delete[] current;
		head = tmp;
		tmp->setPrev(nullptr);
		size--;
	}
	else {
		return;
	}
}
template<class T>
int Array<T>::getSize() {
	return size;
}
template<class T>
void Array<T>::add(T value) {
	Element<T> *temp = new Element<T>(value);
	if (head) {
		temp->setPrev(tail);
		tail->setNext(temp);
		tail = temp;
	}
	else {
		temp->setPrev(nullptr);
		head = tail = temp;
	}
}
template<class T>
T Array<T>::getAt(int index) {
	if (index == 0) {
		return head->value;
	}
	else if (index > 0) {
		Element<T> *newElement = this->head;
		for (int i = 0; i < index; i++) {
			newElement = newElement->next;
		}
		return newElement->value;
	}
	else {
		std::cout << "Неверный индекс!" << std::endl;
	}
}
template<class T>
void Array<T>::setAt(T value, int index) {
	if (index == 0) {
		head->setValue(value);
	}
	else if (index > 0) {
		Element<T> *newElement = this->head;
		for (int i = 0; i < index; i++) {
			newElement = newElement->next;
		}
		newElement->setValue(value);
	}
	else {
		std::cout << "Неверный индекс!" << std::endl;
	}
}
template<class T>
void Array<T>::insertAt(T value, int index) {
	if (index == 0) {
		head = new Element<T>(value, head, tail);
	}
	else {
		Element<T> *newElement = this->head;
		Element<T> *temp = new Element<T>;
		for (int i = 0; i < index - 1; i++) {
			newElement = newElement->next;
		}
		temp->setValue(value);
		if (newElement->next == nullptr) {
			newElement->next = temp;
			temp->next = nullptr;
			temp->prev = newElement;
		}
		else {
			temp->next = newElement->next;
			temp->next->prev = temp;
			newElement->next = temp;
			temp->prev = newElement;
		}
	}
	size++;
}
template<class T>
void Array<T>::removeAt(int index) {
	Element<T> *newElement = this->head;
	if (index == 0) {
		head = head->next;
		delete[] newElement;
	}
	else if (index > 0) {
		for (int i = 0; i < index - 1; i++) {
			newElement = newElement->next;
		}

		Element<T> *temp = newElement->next;
		newElement->setNext(temp->next);
		delete[] temp;
	}
	else {
		std::cout << "Неверный индекс!" << std::endl;
	}
	size--;
}
// Деструктор
template<class T>
Array<T>::~Array() {
	// std::cout << "Объект удален: " << this << std::endl;
}