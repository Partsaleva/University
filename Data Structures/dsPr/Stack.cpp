#include "stdafx.h"
#include "Stack.h"


template <class T>
Stack<T>::Stack() :List(){}

// Adds value to the end of the Stack.
// Complexity: O(1)
template <class T>
void Stack<T>::push(const T& value) {
	list.pushFront(value);
}

// Returns value from the end of the Stack and removes it.
// Complexity: O(n)
template <class T>
T Stack<T>::pop() {
	return list.popFront();
}

// Returns value from the end of the Stack without removing it.
// Complexity: O(n)
template <class T>
T Stack<T>::peek() {
	return list.peek();
}

// Returns the number of elements in the Stack.
// Complexity: O(1)
template <class T>
size_t Stack<T>::size() {
	return list.listSize();
}

template <class T>
void Stack<T>::print(){
	list.print();
}



template class Stack <int>;
template class Stack <char*>;