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
		currSize=0;
		arrCapacity=1;
		arr=new T[arrCapacity];
	};
	~Vector(){
		delete [] arr;
	}


	//  Adds value at a specific index in the Vector.
	void insert(index_type index, const T &value) {	
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		if (index==currSize)
		{
			add(value);
		}
		else
		{
			checkIndex(index);
			if (currSize==arrCapacity)
			{
				doubleSize();
			}

			for (index_type i = currSize; i>index ; i--)
			{
				arr[i]=arr[i-1];
			}
			arr[index]=value;	
			currSize++;
		}

	}


	// Adds value to the end of the Vector.
	void add(const T &value) 
	{
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		if (currSize==arrCapacity)
		{
			doubleSize();
		} 
		arr[currSize++]=value;	
	}


	// Removes element at the specific index
	void remove(index_type index) {
		assert(arr != nullptr);
		assert(currSize<=arrCapacity);

		checkIndex(index);
		currSize--;
		for (index_type i = 0; i < currSize-index; i++)
		{
			arr[index + i] = arr[index + i + 1];
		}

	}

	// Removes element at the last index
	void pop() {
		assert(arr != nullptr);
		assert(currSize <= arrCapacity);

		checkIfEmpty();
		remove(currSize-1);	 		
	}

	// Returns the number of elements in the Vector.
	index_type size() const{
		return currSize;
	}

	void print()const{
		for (index_type i = 0; i < currSize; i++)
		{
			cout<<arr[i]<<" ";
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

		T* doubledArr=new T[2*arrCapacity];
		for (index_type i = 0; i < currSize; i++)
		{
			doubledArr[i]=arr[i];
		}
		delete [] arr;
		arrCapacity*=2;
		arr=doubledArr;
	}	


	void checkIndex(const index_type &index) const{
		if(index < 0 || index >= currSize){
			throw std::out_of_range("Index is out of range");
		}		
	}

	void checkIfEmpty(){
		if(currSize==0){
			throw std::out_of_range("Empty vector");
		}
	}
};


int main(){

	Vector<int> test;

	try{
		test.add(2); test.print(); cout<<endl; //2 	
		test.add(3); test.print(); cout<<endl;//2 3
		test.add(4); test.print(); cout<<endl;//2 3 4
		test.add(5); test.print(); cout<<endl;//2 3 4 5
		cout<<test.get(2);cout<<endl;
		test.insert(0, 1);
		//test.insert(-1, 1);
		//test.insert(4, 1);

		test.print();//1 2 3 4 5  size: 5  
		cout<<"  size: "<<test.size(); cout<<endl;

		test.pop();test.print();cout<<endl;

		/*test.pop();test.print();cout<<endl;
		test.pop();test.print();cout<<endl;
		test.pop();test.print();cout<<endl;
		test.pop();test.print();cout<<endl;
		test.pop();test.print();cout<<endl;*/

		test.print(); cout<<endl;//1 2 3 4 

		test.remove(0); test.print(); cout<<endl;//1 2 3 4
		//test.remove(0); test.print(); cout<<endl;//2 3 4
		//test.remove(2); test.print(); cout<<endl;//2 3
		//test.remove(0); test.print(); cout<<endl;//3
		test.print();//2 3 4  size: 3
		cout<<"  size: "<<test.size();cout<<endl;


		test.remove(2); test.print(); cout<<endl;//2 3
		test.remove(1); test.print(); cout<<endl;//2

		test.pop();
		//test.pop();
	}
	catch(std::out_of_range& or)
	{
		cout<<or.what()<<endl;

	}







	////---------------------------------------------------------------------------------------------------------
	Vector<char*>testChar;
	try{
		testChar.add("b");  testChar.print();//2  
		cout<<endl;

		testChar.add("c"); testChar.print();//2 3
		cout<<endl;

		testChar.add("d"); testChar.print();//2 3 4
		cout<<endl;

		testChar.add("e"); testChar.print();//2 3 4 5
		cout<<endl;	

		testChar.insert(0, "a");
		//testChar.insert(-1,"a");
		//testChar.insert(4, 1);

		testChar.print();//1 2 3 4 5  size: 5  
		cout<<"  size: "<<testChar.size();
		cout<<endl;

		testChar.pop();testChar.print();cout<<endl;

		/*testChar.pop();testChar.print();cout<<endl;
		testChar.pop();testChar.print();cout<<endl;
		testChar.pop();testChar.print();cout<<endl;
		testChar.pop();testChar.print();cout<<endl;
		testChar.pop();testChar.print();cout<<endl;*/

		testChar.print();//1 2 3 4 
		cout<<endl;

		testChar.remove(0); testChar.print(); cout<<endl;//1 2 3 4
		//testChar.remove(0); testChar.print(); cout<<endl;//2 3 4
		//testChar.remove(2); testChar.print(); cout<<endl;//2 3
		//testChar.remove(0); testChar.print(); cout<<endl;//3
		testChar.print();//2 3 4  size: 3
		cout<<"  size: "<<testChar.size();
		cout<<endl;

		testChar.remove(2); testChar.print();//2 3
		cout<<endl;

		testChar.remove(1); testChar.print();//2
		cout<<endl;

		testChar.pop();


	}catch(std::out_of_range& or)
	{
		cout<<or.what()<<endl;

	}

	//---------------------------------------------------------------------------------------------------------------

	Vector<std::string> testString;

	try{
		testString.add("everything");  testString.print(); 
		cout<<endl;

		testString.add("works"); testString.print();
		cout<<endl;

		testString.add("perfect"); testString.print();
		cout<<endl;

		testString.add("but..."); testString.print();
		cout<<endl;	

		testString.insert(0, "not");
		//testString.insert(-1,"a");
		//testString.insert(2, "bla");
		//testString.insert(4, "bla");

		testString.print();//1 2 3 4 5  size: 5  
		cout<<"  size: "<<testString.size();
		cout<<endl;

		testString.pop(); testString.print();//1 2 3 4 
		cout<<endl;

		/*testString.pop();testString.print();cout<<endl;
		testString.pop();testString.print();cout<<endl;
		testString.pop();testString.print();cout<<endl;
		testString.pop();testString.print();cout<<endl;
		testString.pop();testString.print();cout<<endl;*/



		testString.remove(0); testString.print(); cout<<endl;//1 2 3 4
		//testString.remove(0); testString.print(); cout<<endl;//2 3 4
		//testString.remove(2); testString.print(); cout<<endl;//2 3
		//testString.remove(0); testString.print(); cout<<endl;//3
		testString.print();//2 3 4  size: 3
		cout<<"  size: "<<testString.size();
		cout<<endl;

		testString.remove(2); testString.print();//2 3
		cout<<endl;

		testString.remove(1); testString.print();//2
		cout<<endl;

		//testString.pop();
	}
	catch(std::out_of_range& or)
	{
		cout<<or.what()<<endl;

	}
}