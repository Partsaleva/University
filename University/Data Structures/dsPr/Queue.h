#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"
#include <stdexcept>

template<class T>
class Queue : public List<T>
{
public:

	Queue();


	void push(const T &value);
	T pop();
	T peek() const;
	size_t size() const;
	void print()const;

protected:
	List list;
	
};

#endif