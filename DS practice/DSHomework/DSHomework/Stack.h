#ifndef STACK_H
#define STACK_H

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Stack{
public:
	Stack() :top(nullptr),size(0){}

	// Adds value to the end of the Stack.
	void push(const T& value) {
		top = new Node(value, top);
		size++;
	}

	size_t stSize(){
		return size;
	}
	// Returns value from the end of the Stack and removes it.
	T pop() {
		throwIfEmpty();

		T val = top->value;

		Node* temp = top;
		top = top->link;

		delete temp;
		size--;
		return val;
	}

	// Returns value from the end of the Stack without removing it.
	T peek() {

		throwIfEmpty();
		return top->value;

	}

	void print(){
		Node* temp = top;
		while (temp)
		{
			cout << temp->value << " ";
			temp = temp->link;
		}
	}

private:
	struct Node
	{
		T value;
		Node* link;
		Node(const T& value, Node* link) :value(value), link(link){}
	};

	Node* top;
	size_t size;

	void throwIfEmpty() const{
		if (top == nullptr)
		{
			throw std::out_of_range("Empty stack");
		}
	}
};

#endif 
