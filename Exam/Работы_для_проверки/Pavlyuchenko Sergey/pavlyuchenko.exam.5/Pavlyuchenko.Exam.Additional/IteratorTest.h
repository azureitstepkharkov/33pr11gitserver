// � ���� ����� ���������� ����� IteratorTest � ��� ��������� - Iterator

#include "Libraries.h"

// IteratorTest

class IteratorTest {
public:
	virtual bool hasNext() = 0;
	// virtual int current() = 0; // ����� ����� �������������
	// virtual int begin() = 0; // � ����� ������ (�������)
	// virtual int end() = 0; // � ����� ������ (�������)
};

// Iterator

template<class Node, class T>
class Iterator : public IteratorTest {
private: // ��������� �� ������� ����
	Node* ptr;
public: // ������������
	Iterator() : ptr(nullptr) {}
	Iterator(Node* ptr) : ptr(ptr) {}
	~Iterator() {}
public: // ���������
	Iterator& operator ++ () { // ����������� ��������
		if (ptr != nullptr) {
			ptr = ptr->next;
		}
		return *this;
	}
	Iterator operator ++ (int) { // ���������� ��������
		Iterator it(*this);
		++*this;
		return it;
	}
	T& operator*() { // ������������� ������� *it
		return ptr->value;
	}
	bool operator == (const Node* ptr) const {
		return (this->ptr == ptr);
	}
	bool operator != (const Node* ptr) const {
		return (this->ptr != ptr);
	}
public: // ������
	bool hasNext() override {
		return ptr->next == nullptr;
	}
};