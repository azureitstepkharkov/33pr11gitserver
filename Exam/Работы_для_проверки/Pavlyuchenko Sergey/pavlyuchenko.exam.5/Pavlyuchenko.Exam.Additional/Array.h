// � ���� ����� ���������� ���������� ������ Array

#include "Libraries.h"

class Node;
template <class T>
class Array {
private:
	template <class T>
	class Node {
	public:
		T value;
		Node *next;
		Node *prev;
		// ������������
		Node() {
			value = 0;
			next = nullptr;
			prev = nullptr;
		};
		Node(T value, Node *next, Node *prev) {
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
		Node(T value) {
			this->value = value;
			this->next = nullptr;
			this->prev = nullptr;
		}
		// �������
		void setValue(T value) {
			this->value = value;
		}
		void setNext(Node *next) {
			this->next = next;
		}
		void setPrev(Node *prev) {
			this->prev = next;
		}
		// �������
		T getValue() {
			return this->value;
		}
		Node *getNext() {
			return this->next;
		}
		Node *getPrev() {
			return this->prev;
		}
	};
	int size;
	Node<T> *head;
	Node<T> *tail;
public:
	// ������������
	Array();
	Array(const Array &other);
	// �������� ���������� []
	T & operator[](const int index);
	// ��������� + � =
	Array operator+(const Array other);
	Array & operator=(const Array &other);
	// ��������� ������� �������  
	int getSize();
	// ��������� ������� �������  
	void setSize(int size, int grow = 1);
	// ���������� �������� � ������(��� ������������� ������ 
	// ������������� �� �������� grow ������� SetSize)
	void add(T value);
	// ��������� ���������� ������ � �������
	int GetUpperBound() { return size - 1; }
	// IsEmpty � ������ ����?
	bool isEmpty();
	// RemoveAll � ������� ���
	void removeAll(Array<T> &arr);
	// GetAt � ��������� ������������� ��������(�� �������)
	T getAt(int index);
	// SetAt � ��������� ������ �������� ��� ������������� ��������
	void setAt(T value, int index);
	// GetData � ��������� ������ ������� � �������
	Node<T> *getData() { return head; }
	// InsertAt � ������� �������� � �������� �������
	void insertAt(T value, int index);
	// RemoveAt � �������� ��������(-��) � �������� �������
	void removeAt(int index);
	// ������ ������
	void push(T value);
	void del();
	// ����������
	~Array();
public: // ��������
	typedef Iterator<Node<T>, T> iterator;
	Node<T>* begin() { return this->head; }
	Node<T>* end() { return nullptr; }
};
// �����������:
template<class T>
Array<T>::Array() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<class T>
Array<T>::Array(const Array & other) {
	cout << "Object created: " << this << endl;
	this->head = nullptr;
	this->size = 0;
	Node<T> *temp = other.head;
	while (temp) {
		this->push(temp->getValue());
		temp = temp->getNext();
	}
}
// �������� ���������� []
template<class T>
T & Array<T>::Array::operator[](const int index) {
	int counter = 0;
	Node<T> *current = this->head;
	while (current) {
		if (counter == index) {
			return current->value;
		}
		current = current->next;
		counter++;
	}
}

// ��������� + � =
template<class T>
Array<T> Array<T>::operator+(const Array other) {
	Array<T> temp;
	Node<T> *j = other.head;
	for (Node<T> *i = this->head; i != nullptr && j != nullptr; i = i->getNext()) {
		temp.push(i->getValue() + j->getValue());
		j = j->getNext();
	}
	return temp;
}
template<class T>
Array<T> & Array<T>::operator=(const Array & other) {
	/*cout << "������ ������: " << this << endl;*/
	Node<T> *temp = other.head;
	while (temp) {
		this->push(temp->getValue());
		temp = temp->getNext();
	}
	return *this;
}

// ���������� �������:
template<class T>
void Array<T>::push(T value) {
	Node<T> *temp = new Node<T>(value);
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
		Node<T> *tmp = head;
		Node<T> *current = tail;
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
void Array<T>::setSize(int size, int grow) {
	if (this->size < size) {
		grow = freeExtra(this->size, size);
		this->size += grow;
	}
}
template<class T>
void Array<T>::add(T value) {
	Node<T> *temp = new Node<T>(value);
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
bool Array<T>::isEmpty() {
	if (size == 0) {
		return false;
	}
	else {
		return true;
	}
}
template<class T>
void Array<T>::removeAll(Array<T> &arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		arr.del();
	}
}
template<class T>
T Array<T>::getAt(int index) {
	if (index == 0) {
		return head->value;
	}
	else if (index > 0) {
		Node<T> *newNode = this->head;
		for (int i = 0; i < index; i++) {
			newNode = newNode->next;
		}
		return newNode->value;
	}
	else {
		cout << "�������� ������!" << endl;
	}
}
template<class T>
void Array<T>::setAt(T value, int index) {
	if (index == 0) {
		head->setValue(value);
	}
	else if (index > 0) {
		Node<T> *newNode = this->head;
		for (int i = 0; i < index; i++) {
			newNode = newNode->next;
		}
		newNode->setValue(value);
	}
	else {
		cout << "�������� ������!" << endl;
	}
}
template<class T>
void Array<T>::insertAt(T value, int index) {
	if (index == 0) {
		head = new Node<T>(value, head, tail);
	}
	else {
		Node<T> *newNode = this->head;
		Node<T> *temp = new Node<T>;
		for (int i = 0; i < index - 1; i++) {
			newNode = newNode->next;
		}
		temp->setValue(value);
		if (newNode->next == nullptr) {
			newNode->next = temp;
			temp->next = nullptr;
			temp->prev = newNode;
		}
		else {
			temp->next = newNode->next;
			temp->next->prev = temp;
			newNode->next = temp;
			temp->prev = newNode;
		}
	}
	size++;
}
template<class T>
void Array<T>::removeAt(int index) {
	Node<T> *newNode = this->head;
	if (index == 0) {
		head = head->next;
		delete[] newNode;
	}
	else if (index > 0) {
		for (int i = 0; i < index - 1; i++) {
			newNode = newNode->next;
		}

		Node<T> *temp = newNode->next;
		newNode->setNext(temp->next);
		delete[] temp;
	}
	else {
		cout << "�������� ������!" << endl;
	}
	size--;
}
// ����������
template<class T>
Array<T>::~Array() {
	/*cout << "������ ������: " << this << endl;*/
}
// k. Append � "��������" ���� ��������
template<class T>
Array<T> append(Array<T> &first, Array<T> &second) {
	Array<T> temp;
	temp = first + second;
	return temp;
}