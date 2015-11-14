#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

using std::cout;
using std::endl;
 


class Set{
	typedef size_t index_type;
public:
	Set(){
		size = 0;
		capacity = 1;
		arr = new int[capacity];
	}

	Set(const Set &orig){
		copy(orig);
	}

	Set& operator=(const Set &orig){
		if (this != &orig){
			del();
			copy(orig);
		}
		return *this;
	}


	void copy(const Set &orig){
		size = orig.size;
		capacity = orig.capacity;
		arr = new int[orig.size];
		memcpy(arr, orig.arr, sizeof(int) * size);
	}
	
	void del(){
		delete[] arr;
	}
	~Set(){
		del();
	}


	void add(const int &value){
		if (!found(value)){
			if (size == capacity)
			{
				doubleSize();
			}
			arr[size] = value;
			size++;
		}
	}

	bool found(const int &value){
		for (index_type i = 0; i < size; i++)
		{
			if (value == arr[i]){
				return true;
			}
		}
		return false;
	}

	void remove(const int &value){
		if (found(value)){
			size--;
			for (index_type i = 0; i < size; i++)
			{
				if (value == arr[i]){
					for (index_type j = 0; j < size - i; j++)
					{
						arr[i + j] = arr[i + j + 1];
					}
				}
			}
		}
	}
	
	Set setUnion(Set &t){
		Set result;
		for (index_type i = 0; i < (*this).size; i++){
			result.add(arr[i]);
		}

		for (index_type i = 0; i < t.size; i++){
			result.add(t.arr[i]);
		}
		
		return result;
	}


	// : returns the intersection of sets S and T.
	Set intersection(Set &t){
		Set result;
		Set help;
		for (index_type i = 0; i < t.size; i++)
		{
			help.add(t.arr[i]);
		}
		for (index_type i = 0; i < help.size; i++)
		{
			if (found(t.arr[i])){
				result.add(t.arr[i]);
			}
		}
		return result;
	}

	Set bigger(Set &t, Set &s){
		if (t.size>s.size){
			return t;
		}
		else
			return s;
	}
	// : returns the difference of sets S and T.
	Set difference(Set &t){
		Set result=*this;
		Set bigg = bigger(result, t);
		for (index_type i = 0; i <bigg.size; i++)
		{
			result.remove(t.arr[i]);
		}
		return result;
	}

	// : a predicate that tests whether the set S is a subset of set T.
	bool isSubset(Set &t){
		index_type count = 0;
		for (index_type i = 0; i < t.size; i++){
			if (found((*this).arr[i])){
				count++;			
			}
		}
		if (count == (*this).size){
			return true;
		}
		else {
			return false;
		}
	}
		
	void print(){
		for (index_type i = 0; i < size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	//-------------------private----------------------//
private:
	int *arr;
	index_type capacity;
	index_type size;


	void doubleSize(){

		int* doubledArr = new int[2 * capacity];
		for (index_type i = 0; i < size; i++)
		{
			doubledArr[i] = arr[i];
		}
		delete[] arr;
		capacity *= 2;
		arr = doubledArr;
	}
	
};

int main(){

	Set s,s1,s2,s3,s4,s5;
		
	s.add(2); s.add(3); s.add(4); s.add(5); s.add(6);
	s1.add(7); s1.add(8); s1.add(9); s1.add(2);
	s1.add(10); s1.add(11);		s1.add(4);
	s.print();
	s1.print();

	s2=s.setUnion(s1);
	s2.print();

	s3 = s.intersection(s1);
	s3.print();

	s4=s.difference( s1);
	s4.print();

	cout << s.isSubset(s2)<<endl;
	


	return 0;
}