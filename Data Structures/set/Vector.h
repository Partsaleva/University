// vector.cpp : Defines the entry point for the console application.
#ifndef VECTOR_H
#define VECTOR_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <iterator>


using std::cout;
using std::endl;
using std::iterator;

class Vector {
public:
	typedef size_t index_type;

	Vector(){
		currSize = 0;
		arrCapacity = 1;
		arr = new int[arrCapacity];
	}
	~Vector(){
		delete[] arr;
	}

	Vector(const Vector &orig){
		copy(orig);
	}

	Vector& operator =(const Vector &orig){
		if (&orig != this){
			delete[] arr;
			copy(orig);
		}
		return *this;
	}
	//  Adds value at a specific index in the Vector.
	void insert(index_type index, const int &value) {
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		if (index == currSize)
		{
			add(value);
		}
		else
		{
			checkIndex(index);
			if (currSize == arrCapacity)
			{
				doubleSize();
			}

			for (index_type i = currSize; i>index; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[index] = value;
			currSize++;
		}

	}


	// Adds value to the end of the Vector.
	void add(const int &value)
	{
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		if (currSize == arrCapacity)
		{
			doubleSize();
		}
		
		arr[currSize++] = value;
		for (int i = currSize - 1; i > 0; i--) {
			if (arr[i - 1] < arr[i]){
				break;
			}
			std::swap(arr[i - 1], arr[i]);
		}
	}


	// Removes element at the specific index
	void remove(index_type index) {
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		checkIndex(index);
		currSize--;
		for (index_type i = 0; i < currSize - index; i++)
		{
			arr[index + i] = arr[index + i + 1];
		}

	}

	// Removes element at the last index
	void pop() {
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		checkIfEmpty();
		remove(currSize - 1);
	}

	// Returns the number of elements in the Vector.
	index_type size() const{
		return currSize;
	}

	void print()const{
		for (index_type i = 0; i < currSize; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	index_type get(index_type index) const{
		checkIndex(index);
		return arr[index];
	}

	// Returns the total capacity of the Vector.
	index_type capacity() const{
		return arrCapacity;
	}

	index_type begin() const
	{	
		return 0;
	}

	index_type end() const
	{
		return currSize;
	}

	
protected:
	int *arr; 
	index_type currSize;
	index_type arrCapacity;

	
	
	void doubleSize(){
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		int* doubledArr = new int[2 * arrCapacity];
		for (index_type i = 0; i < currSize; i++)
		{
			doubledArr[i] = arr[i];
		}
		delete[] arr;
		arrCapacity *= 2;
		arr = doubledArr;
	}


	void checkIndex(const index_type &index) const{
		if (index < 0 || index >= currSize){
			throw std::out_of_range("Index is out of range");
		}
	}

	void checkIfEmpty(){
		if (currSize == 0){
			throw std::out_of_range("Empty vector");
		}
	}

	void copy(const Vector &orig){
		currSize = orig.currSize;
		arrCapacity = orig.arrCapacity;
		arr = new int[orig.arrCapacity];
		for (index_type i = 0; i < currSize; i++){
			arr[i] = orig.arr[i];
		}
	}
};

#endif


