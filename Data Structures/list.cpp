// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template<class T>
class List{

public:
	List() :head(nullptr), tail(nullptr), size(0){}

	~List(){
		Node* curr = head;
		Node* temp;
		while (curr != nullptr)
		{
			temp = curr->link;
			delete curr;
			curr = temp;
		}
	}

	//throw exception if the list is empty
	void throwIfEmpty()const{
		if (head == nullptr)
		{
			throw std::out_of_range("Empty!");
		}
	}

	//check position between 0 and size-1
	void checkIfValidPosition(const size_t &pos)const{
		if (pos < 0 || pos >= size)
		{
			throw std::out_of_range("Invalid position");
		}
	}


	void pushFront(const T &value){
		cout << "pushFront: " << value << endl;
		head = new Node(value, head);
		if (tail == nullptr)
		{
			tail = head;
		}
		size++;
	}

	void pushBack(const T &value){
		cout << "pushBack: " << value << endl;
		Node* newNode = new Node(value);
		if (head == nullptr && tail == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->link = newNode;
			tail = newNode;
		}
		size++;
	}


	T popFront(){
		throwIfEmpty();
		T val = head->value;
		cout << "popFront: " << val << endl;
		Node* temp = nullptr;

		temp = head;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head->link;

		}
		delete temp;
		size--;
		return val;
	}

	T popBack(){
		throwIfEmpty();
		T val = tail->value;
		cout << "popBack: " << val << endl;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			Node* curr = nullptr;
			Node* prev = nullptr;

			curr = head;
			while (curr->link != nullptr) {
				prev = curr;
				curr = curr->link;
			}
			tail = prev;
			prev->link = nullptr;
			delete curr;
		}
		size--;
		return val;
	}


	void insert(const size_t position, const T &value){
		cout << "insert " << value << " at " << position << " index" << endl;
		Node* newNode = new Node(value);
		Node* curr = nullptr;
		if (position == size)
		{
			;
		}
		else
		{
			checkIfValidPosition(position);
		}

		curr = head;
		if (head == nullptr && tail == nullptr)
		{
			head = tail = newNode;
		}
		else if (position == 0)
		{
			head = newNode;
			newNode->link = curr;
		}
		else
		{
			for (size_t i = 0; i < position - 1; i++)
			{
				curr = curr->link;
			}

			newNode->link = curr->link;
			curr->link = newNode;

		}
		size++;
	}



	void remove(const T& value) {
		cout << "remove: " << value << endl;
		Node* curr = nullptr;
		Node* prev = nullptr;

		curr = head;
		while (curr != nullptr && value != curr->value) {
			prev = curr;
			curr = curr->link;
		}

		if (curr != nullptr) {
			if (curr == tail)
			{
				tail = prev;
			}
			// found the node, have to delete it
			if (prev != nullptr) {
				// not the first element
				prev->link = curr->link;
			}
			else {
				// removing the first element
				curr = head;
				head = head->link;
				
			}
			delete curr;
		}
		size--;
	}


	bool find(const T &value)const{
		Node* curr = nullptr;

		curr = head;
		while (curr != nullptr)
		{
			if (curr->value == value)
			{
				return true;
			}
			curr = curr->link;
		}
		return false;
	}

	void sort(){
		Node* first = nullptr;

		if (head == nullptr || head->link == nullptr){
			first = tail = head;
		}
		else
		{
			while (head != nullptr) {

				Node* curr = head;
				head = head->link;
				if (first == nullptr) 
				{
					curr->link = first;
					first = curr;
				}
				else if (curr->value <= first->value)
				{
					if (first->value > tail->value)
					{
						tail = first;
					}
					curr->link = first;
					first = curr;
				}
				else
				{
					Node* p = first;
					while (p != nullptr) {
						if (p->link == nullptr || curr->value <= p->link->value)
						{
							if (p->link != nullptr && p->link->value > tail->value)
							{
								tail = p->link;
							}
							curr->link = p->link;
							p->link = curr;
							break;
						}
						p = p->link;
					}
				}
			}
		}
		head = first;

	}


	void reverse(){
		Node* curr = nullptr;
		Node* prev = nullptr;
		Node* next = nullptr;

		tail = curr = head;
		while (curr != nullptr)
		{
			next = curr->link;
			curr->link = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	void print()const{
		Node* curr = head;
		while (curr)
		{
			cout << curr->value << ' ';
			curr = curr->link;
		}
	}

	size_t listSize()const{
		return size;
	}

private:
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
};

bool test1();
bool test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();

int main()
{

	List<int>r;
	//r.sort();
	cout << "sort empty: "; r.print(); cout << endl;
	r.pushBack(7);
	//cout << "sort one: "; r.sort();
	r.print(); cout << endl;
	r.pushBack(1);
	r.pushBack(3);
	r.pushBack(5);
	r.pushBack(2);
	r.pushBack(4);
	cout << "original list: "; r.print(); cout << endl;
	cout << "sorted list: "; r.sort(); r.print(); cout << endl;
	r.pushBack(1);
	r.print(); cout << endl;
	r.pushFront(9);
	r.print(); cout << endl;
	r.sort();
	r.print(); cout << endl;
	r.popFront();
	r.print(); cout << endl;
	r.popBack();
	r.print(); cout << endl;
	r.sort();
	r.print(); cout << endl;
	r.print(); cout << endl;
	cout << endl;



	List<int>n;
	n.pushBack(1);
	n.pushBack(2);
	n.pushBack(3);
	n.pushBack(4);
	n.pushBack(5);
	n.print(); cout << endl;
	n.reverse();
	n.print(); cout << endl;
	n.pushBack(6);
	n.print(); cout << endl;
	n.pushFront(0);
	n.print(); cout << endl;
	n.popBack();
	n.print(); cout << endl;
	n.popFront();
	n.print(); cout << endl;
	cout << endl;

	List<int> l;
	l.pushBack(1);
	l.pushBack(2);
	l.remove(2);
	l.pushBack(3);
	l.print(); cout << endl;
	cout << endl;

	List<int> m;
	m.pushBack(2);
	m.insert(0, 1);
	m.pushBack(3);
	m.print(); cout << endl;
	cout << endl;

	test1(); cout << endl;
	test2(); cout << endl;
	test3(); cout << endl;
	test4(); cout << endl;
	test5(); cout << endl;
	test6(); cout << endl;
	test7(); cout << endl;
	test8(); cout << endl;
	test9(); cout << endl;
	test10(); cout<< endl;

	return 0;
}

bool test1(){
	List<int> l;
	try {
		l.popBack();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		cout << "test1: popBack() from empty list throw!" << endl;
		return true;
	}
	return false;
}

bool test2(){
	List<int> l;
	try {
		l.popFront();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		cout << "test2: popFront() from empty list throw!" << endl;
		return true;
	}
	return false;
}

void test3()
{
	cout << "test 3: pushFront(*) popBack()" << endl;
	List<int> list1;
	try
	{
		list1.pushFront(42);
		list1.popBack();
		cout << "print: ";  list1.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}

}

void test4()
{
	cout << "test 4: pushFront(*) popFront()" << endl;
	List<int> list1;
	try
	{
		list1.pushFront(42);
		list1.popFront();
		cout << "print: ";  list1.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}

}

void test5(){
	cout << "test 5: pushBack(*) popBack()" << endl;
	List<int> list2;
	try{
		list2.pushBack(43);
		list2.popBack();
		cout << "print: ";  list2.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}

void test6(){
	cout << "test 6: pushBack(*) popFront()" << endl;
	List<int> list2;
	try{
		list2.pushBack(43);
		list2.popFront();
		cout << "print: ";  list2.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}

void test7(){
	cout << "test 7: push order" << endl;
	List<int> list;
	try{
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushFront(4);
		list.pushFront(5);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		cout << list.find(1);
		cout << list.find(2);
		cout << list.find(3);
		cout << list.find(4);
		cout << list.find(5);
		cout << list.find(7);
		cout << list.find(6);
		cout << list.find(8);
		cout << list.find(9);
		cout << list.find(0);
		cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}

void test8(){
	cout << "test 8: push front and back" << endl;
	List<int> list;
	try{
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushFront(4);
		list.pushFront(5);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		list.popFront();
		cout << "print: ";  list.print(); cout << endl;
		list.popBack();
		cout << "print: ";  list.print(); cout << endl;
		list.pushFront(3);
		cout << "print: ";  list.print(); cout << endl;
		list.pushBack(9);
		cout << "print: ";  list.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}

void test9(){
	cout << "test 9: insert" << endl;
	List<int> list;
	try{
		list.insert(0, 9);
		cout << "print: ";  list.print(); cout << endl;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushFront(4);
		list.pushFront(5);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		list.insert(0, 6);
		cout << "print: ";  list.print(); cout << endl;
		cout << "size: " << list.listSize() << endl;
		list.insert(list.listSize(), 5);
		cout << "print: ";  list.print(); cout << endl;
		cout << "size" << list.listSize() << endl;
		list.insert(3, 1);
		cout << "print: ";  list.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}

void test10(){
	cout << "test 10: remove" << endl;
	List<int> list;
	try{
		list.pushBack(1);
		list.pushFront(4);
		list.pushBack(2);
		list.pushFront(5);
		list.pushBack(3);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		list.remove(4);
		cout << "print: ";  list.print(); cout << endl;
		//list.remove(6);
		//cout << "print: ";  list.print(); cout << endl;
		list.remove(7);
		cout << "print: ";  list.print(); cout << endl;
		list.remove(3);
		cout << "print: ";  list.print(); cout << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
	}
}