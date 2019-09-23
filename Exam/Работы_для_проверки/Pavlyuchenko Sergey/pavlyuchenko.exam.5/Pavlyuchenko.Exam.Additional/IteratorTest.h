// В этом файле содержится класс IteratorTest и его наследник - Iterator

#include "Libraries.h"

// IteratorTest

class IteratorTest {
public:
	virtual bool hasNext() = 0;
	// virtual int current() = 0; // Делаю через разыменование
	// virtual int begin() = 0; // В самом списке (массиве)
	// virtual int end() = 0; // В самом списке (массиве)
};

// Iterator

template<class Node, class T>
class Iterator : public IteratorTest {
private: // Указатель на текущий узел
	Node* ptr;
public: // Конструкторы
	Iterator() : ptr(nullptr) {}
	Iterator(Node* ptr) : ptr(ptr) {}
	~Iterator() {}
public: // Операторы
	Iterator& operator ++ () { // Постфиксный итератор
		if (ptr != nullptr) {
			ptr = ptr->next;
		}
		return *this;
	}
	Iterator operator ++ (int) { // Префиксный итератор
		Iterator it(*this);
		++*this;
		return it;
	}
	T& operator*() { // Разыменование объекта *it
		return ptr->value;
	}
	bool operator == (const Node* ptr) const {
		return (this->ptr == ptr);
	}
	bool operator != (const Node* ptr) const {
		return (this->ptr != ptr);
	}
public: // Методы
	bool hasNext() override {
		return ptr->next == nullptr;
	}
};