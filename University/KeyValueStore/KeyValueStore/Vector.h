 // vector.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

		 using std::cout;
using std::endl;

template<class T>
class Vector {
public:
	typedef size_t index_type;

	Vector(){
		currSize = 0;
		arrCapacity = 1;
		arr = new T[arrCapacity];
	};
	~Vector(){
		delete[] arr;
	}


	//  Adds value at a specific index in the Vector.
	void insert(index_type index, const T &value) {
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
	void add(const T &value)
	{
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		if (currSize == arrCapacity)
		{
			doubleSize();
		}
		arr[currSize++] = value;
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
	}

	T get(index_type index) const{
		checkIndex(index);
		return arr[index];
	}

	// Returns the total capacity of the Vector.
	index_type capacity() const{
		return arrCapacity;
	}

private:
	T *arr;
	index_type currSize;
	index_type arrCapacity;

	void doubleSize(){
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		T* doubledArr = new T[2 * arrCapacity];
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
};

