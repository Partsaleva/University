#ifndef STACK_H
#define STACK_H

#include "List.h"
#include <stdexcept>

template <class T>
class Stack :public List<T>
{
public:
	Stack();
	void push(const T& value);
	T pop();
	T peek();
	size_t size();
	void print();

private:
	List list;
	
};

#endif