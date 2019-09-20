// В этом файле содержатся реализация класса List

#include "Libraries.h"

// ListNode

template <class T>
class ListNode {
private:
	T data; // Данные
public:
	ListNode* next;
	ListNode* prev;
	// Конструктор
	ListNode(T data) {
		this->data = data;
	}
	// Методы
	T getData() {
		return this->data;
	}
	string toString() {
		stringstream s;
		s << this->getData();
		return s.str();
	}
	// Деструктор
	~ListNode() {}
};

// List

template <class T>
class List {
private:
	T* head; // Голова
	T* tail; // Хвост
	int size; // Размер
public:
	// Конструктор
	List() {
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	// Методы
	T* getHead() {
		return this->head;
	}
	T* getTail() {
		return this->tail;
	}
	int getSize(bool update = false) {
		if (!update) {
			return this->size;
		}
		int size = 0;
		T* temp = this->head;
		while (temp) {
			size++;
			temp = temp->next;
		}
		this->size = size;
		return this->size;
	}
	void push_front(T* new_node) {
		new_node->next = nullptr;
		new_node->prev = nullptr;

		if (this->head == nullptr) {
			this->head = new_node;
			this->tail = this->head;
			this->size = this->size + 1;
		}
		else {
			this->head->prev = new_node;
			new_node->next = this->head;
			this->head = new_node;
			this->size = this->size + 1;
		}
	}
	void push_back(T* new_node) {
		new_node->next = nullptr;
		new_node->prev = nullptr;

		if (this->head == nullptr) {
			this->head = new_node;
			this->tail = this->head;
			this->size = this->size + 1;
		}
		else {
			this->tail->next = new_node;
			new_node->prev = this->tail;
			this->tail = new_node;
			this->size = this->size + 1;
		}
	}
	void push(T* new_node) {
		this->push_front(new_node);
	}
	T* pop() {
		T* temp = this->head;
		this->head = this->head->next;
		this->head->prev = nullptr;
		this->size = this->size - 1;
		return temp;
	}
	T* peek() {
		return this->head;
	}
	void enqueue(T* new_node) {
		this->push_back(new_node);
	}
	T* dequeue() {
		return this->pop();
	}
	T* get(int index) {
		if (index == 0) {
			return this->head;
		}
		else if (index == this->size - 1) {
			return this->tail;
		}
		else if (index < 0 || index >= this->size) {
			return nullptr;
		}
		if (index < this->size / 2) {
			T* temp = this->head;
			int i = 0;
			while (temp) {
				if (i == index) { return temp; }
				i++;
				temp = temp->next;
			}
		}
		else {
			T* temp = this->tail;
			int i = this->size - 1;
			while (temp) {
				if (i == index) { return temp; }
				i--;
				temp = temp->prev;
			}
		}
		return nullptr;
	}
	// Оператор вывода
	friend ostream& operator<<(ostream& out, List<T> obj) {
		out << "[HEAD] -> ";
		T* temp = obj.getHead();
		while (temp) {
			out << temp->toString() << " -> ";
			temp = temp->next;
		}
		out << "[TAIL]" << endl;
		
		return out;
	}	
	// Деструктор
	~List() {
		while (this->head) {
			T* next = this->head->next;
			delete this->head;
			this->size = this->size - 1;
			this->head = next;
		}
	}
};