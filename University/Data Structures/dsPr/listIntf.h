#ifndef LISTINTF_H
#define LISTINTF_H
#include "stdafx.h"
template<class T>
class ListIntf
{
public:
	
	virtual void pushFront(const T &value) = 0;
	virtual void pushBack(const T &value) = 0;
	virtual T popFront() = 0;
	virtual T popBack() = 0;
	virtual void insert(const size_t position, const T &value) = 0;
	virtual void remove(const T& value) = 0;
	virtual bool find(const T &value)const = 0;
	virtual void sort() = 0;
	virtual void reverse() = 0;
	virtual void print() const = 0;
	virtual size_t listSize() const = 0;
	virtual T peek()const = 0;


	virtual ~ListIntf(){}

};

#endif