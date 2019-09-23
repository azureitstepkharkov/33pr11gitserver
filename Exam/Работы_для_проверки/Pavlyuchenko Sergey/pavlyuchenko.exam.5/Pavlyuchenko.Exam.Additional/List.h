// В этом файле содержатся реализация класса List

#include "Libraries.h"
#include "IteratorTest.h"

// List
template<class T>
class List {
	// Node
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};
private: // Голова, хвост, размер списка
	Node* head;
	Node* tail;
	int size;
public: // Конструкторы
	List() : head(nullptr), tail(nullptr), size(0) { /*cout << "Объект создан: " << this << endl;*/ }
	List(const List &obj) {
		this->head = this->tail = nullptr;
		this->size = 0;
		Node *temp = obj.head;
		while (temp != nullptr) {
			push_back(temp->value);
			temp = temp->next;
		}
	}
	~List() {
		/*cout << "Объект удален: " << this << endl;*/
		this->clear();
	}
public: // Итератор
	typedef Iterator<Node, T> iterator;
	Node* begin() { return this->head; }
	Node* end() { return nullptr; }
	friend ostream& operator<<(ostream& out, List &obj) {
		if (obj.size != 0) {
			Node *temp = obj.head;
			while (temp->next != nullptr) {
				out << temp->value << ", ";
				temp = temp->next;
			}
			out << temp->value << endl;
		}

		return out;
	}
public: // Методы
	void push_front(const T& value) {
		Node* temp = new Node();
		temp->prev = nullptr;
		temp->value = value;
		temp->next = this->head;
		if (this->head != nullptr) {
			this->head->prev = temp;
		}
		if (this->size == 0) {
			this->head = this->tail = temp;
		}
		else {
			this->head = temp;
		}
		this->size++;
	}
	void push_back(const T& value) {
		Node* temp = new Node();
		temp->next = nullptr;
		temp->value = value;
		temp->prev = this->tail;
		if (this->tail != nullptr) {
			this->tail->next = temp;
		}
		if (this->size == 0) {
			this->head = this->tail = temp;
		}
		else {
			this->tail = temp;
		}
		this->size++;
	}
	T* pop() {
		T* temp = this->head;
		this->head = this->head->next;
		this->head->prev = nullptr;
		this->size--;
		return temp;
	}
	bool empty() const {
		return (this->head == nullptr);
	}
	int getSize() const {
		return size;
	}
	void clear() {
		Node* tmp;
		while (this->head != nullptr) {
			tmp = this->head;
			this->head = head->next;
			delete tmp;
		}
		tail = nullptr;
		size = 0;
	}
};