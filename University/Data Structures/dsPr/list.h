#ifndef LIST_H
#define LIST_H

#include "ListIntf.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template<class T>
class List :public ListIntf<T>
{
public:
	List();
	~List()override;
	void pushFront(const T &value) override;
	void pushBack(const T &value)override;
	T popFront()override;
	T popBack()override final;
	void insert(const size_t position, const T &value)override final;
	void remove(const T& value)override final;
	bool find(const T &value)const override final;
	void sort()override final;
	void reverse()override final;
	void print()const override;
	size_t listSize()const override;
	T peek()const override;

protected:
	struct Node{
		T value;
		Node* link;
		Node() :value(), link(nullptr){}
		Node(const T &value) :value(value), link(nullptr){}
		Node(const T &value, Node* link) :value(value), link(link){}
	};
	size_t size;
	Node* head;
	Node* tail;
	//throw exception if the list is empty
	void throwIfEmpty() const;
	//check position between 0 and size-1
	void checkIfValidPosition(const size_t &pos) const ;
};

#endif