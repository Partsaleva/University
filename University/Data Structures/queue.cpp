// queue.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

using std::cout;
using std::endl;

template<class T>
class Queue {
public:
	Queue():front(nullptr), back(nullptr),currSize(0){}

	// Adds value to the end of the Queue.
	// Complexity: O(1)
	void push(const T &value) {
		Node* temp=new Node(value);
		if (front==nullptr && back == nullptr) 
		{
			front=back=temp;

		}else{
			back->link=temp;
			back=temp;
		}
		currSize++;
	}

	// Returns value from the front of the Queue and removes it.
	// Complexity: O(1)
	T pop() {	
		throwIfEmpty();
		currSize--;
		T val=front->value;	
		Node* temp=front;
		if (front==back)
		{
			front=back=nullptr;
		}
		else{

			front=front->link;
		}
		delete temp;
		return val;
		
	}

	//// Returns value from the front of the Queue without removing it.
	//// Complexity: O(1)
	T peek() const{
		throwIfEmpty();
		return front->value;

	}

	// Returns the number of elements in the Queue.
	// Complexity: O(1)
	size_t size() const{
		return currSize;
	}


	void print()const{
		Node* temp=front;
		while (temp)
		{
			cout<<temp->value<<" ";
			temp=temp->link;
		}
	}

private:
	struct Node{
		T value;
		Node* link;
		Node():value(), link(nullptr){}
		Node(const T& value):value(value), link(nullptr){}
	};
	size_t currSize;
	Node* front;
	Node* back;

	void throwIfEmpty() const{  
		if (front==nullptr)
		{
			throw std::out_of_range("Empty queue!");
		}
	}
};

//

int main()
{
	cout<<"test 1: pop() from empty"<<endl;
	Queue <int> q;
	try {
		cout<<q.pop();
	}
	catch(std::out_of_range& err)
	{
		cout<<err.what()<< endl;
	}

	cout<<endl;
	cout<<"test 2: push and pop() "<<endl;


	Queue <int> qq;
	try{
		qq.push(22);
		cout<<qq.pop()<<endl;
	}
	catch(std::out_of_range& err){

		cout<<err.what()<< endl;
	}

	cout<<endl;
	cout<<"test 3: "<<endl;

	Queue<int>test;
	try{
		test.push(1);
		test.push(2); test.push(3); test.push(4);
		test.print();  cout <<  endl;

		cout<<"size: "<<test.size()<< endl;
		cout<<"pop:"<<test.pop()<< endl;
		test.print();  cout <<  endl;
		cout<<"size: "<<test.size()<< endl;

		cout<<"pop:"<<test.pop()<< endl;;
		cout<<"pop:"<<test.pop()<< endl;;
		cout <<"Peek: "<< test.peek()<< endl;;
	}
	catch(std::out_of_range& err)
	{

		cout<<err.what()<< endl;
	}
	//----------------------------------------------------------------------------------------------------------------
	cout<<endl;
	cout<<"test 4: char*"<<endl;

	Queue<char*>testChar;
	//Queue< string>testChar;
	try{
		testChar.push("a");
		testChar.push("b"); testChar.push("c"); testChar.push("d");
		testChar.print();  cout <<  endl;

		cout<<"size: "<<testChar.size()<< endl;
		cout<<"pop: "<<testChar.pop()<< endl;
		testChar.print();  cout <<  endl;
		cout<<"size: "<<testChar.size()<< endl;
		cout <<"Peek: "<<testChar.peek()<< endl;;
		cout <<  endl;

	}
	catch(std::out_of_range& err)
	{
		cout<<err.what()<< endl;
	}

	//-----------------------------------------------------------------------------------------------

	cout<<endl;
	cout<<"test 5: char*"<<endl;

	Queue<char*> testC;
	try{
		testC.push("alabala");
		cout << "pop: " << testC.pop() <<  endl; 
		cout <<"Peek: " << testC.peek()<< endl;
		cout << "pop: " << testC.pop() <<  endl;
	}catch(std::out_of_range& err)
	{
		cout<<err.what()<< endl;
	}


	return 0;
}



