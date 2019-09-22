// В этом файле содержится класс IteratorList

#include "Libraries.h"
#include "List.h"
#include "Array.h"

// IteratorTest

class IteratorTest {
public:
	virtual bool hasNext() = 0;
	virtual int current() = 0;
	virtual int begin() = 0;
	virtual int end() = 0;
};

// IteratorList
/*
template <class T>
class IteratorList: public IteratorTest {
public:
	IteratorList() {}
	IteratorList(List<T> &list) : list (list), current(0) {}
	bool hasNext() override {
		return current < list.getSize();
	}
	int current() override {
		return 0;
	}
	int begin() override {
		return 0;
	}
	int end() override {
		return 0;
	}
private:
	List<T> list;
	int current = 0;
};
*/

template <class ListNode>
class IteratorList : public IteratorTest {
	friend class List<class ListNode::value_type>;
	ListNode* p;
public:
	IteratorList(ListNode* p) : p(p) {}
	IteratorList(const IteratorList& other) : p(other.p) {}
	IteratorList& operator=(IteratorList other) { std::swap(p, other.p); return *this; }
	void operator++() { p = p->next; }
	void operator++(int) { p = p->next; }
	bool operator==(const IteratorList& other) { return p == other.p; }
	bool operator!=(const IteratorList& other) { return p != other.p; }
	const int& operator*() const { return p->data; }
	IteratorList<ListNode> operator+(int i)	{
		IteratorList<ListNode> iter = *this;
		while (i-- > 0 && iter.p)
		{
			++iter;
		}
		return iter;
	}
};