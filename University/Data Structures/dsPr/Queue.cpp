#include "stdafx.h"
#include "Queue.h"

template<class T>
Queue<T>::Queue() :List(){}




template<class T>
void Queue<T>::push(const T &value) {
	list.pushBack(value);
}

template<class T>
T Queue<T>::pop() {
	return list.popFront();
}

template<class T>
T Queue<T>::peek() const{
	return list.peek();

}

template<class T>
size_t Queue<T>::size() const{
	return list.listSize();
}

template<class T>
void Queue<T>::print()const{
	list.print();
}



template class Queue <int>;
template class Queue <char*>;