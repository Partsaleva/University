// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;

template<class T>
class Stack{
public:
	Stack():top(nullptr), ssize(0){}

	// Adds value to the end of the Stack.
	// Complexity: O(1)
	void push(const T& value) {
		top=new Node(value, top);
		ssize++;
	}

	// Returns value from the end of the Stack and removes it.
	// Complexity: O(n)
	T pop() {
		throwIfEmpty();

		T val=top->value;
		ssize--;

		Node* temp=top;
		top=top->link;

		delete temp;
		return val;
	}

	// Returns value from the end of the Stack without removing it.
	// Complexity: O(n)
	T peek() {

		throwIfEmpty();
		return top->value;

	}

	// Returns the number of elements in the Stack.
	// Complexity: O(1)
	size_t size() {
		return ssize;
	}

	void print(){
		Node* temp=top;
		while (temp)
		{
			cout<<temp->value<<" ";
			temp=temp->link;
		}
	}

private:
	struct Node
	{
		T value;
		Node* link;
		Node(const T& value, Node* link):value(value),link(link){}
	};

	size_t ssize;
	Node* top;


	void throwIfEmpty() const{  
		if (top==nullptr)
		{
			throw std::out_of_range("Empty stack");
		}
	}
};



int main()
{


	Stack<int> test;
	try{
		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);
		test.print(); 
		cout<<"size: "<<test.size()<< endl; //  4 3 2 1 size: 4
		cout<<"returned value from the top(and removed): "<<test.pop()<<  endl; // 4
		test.print();
		cout<<"size: "<<test.size()<< endl; //  3 2 1 size: 3
		cout <<"Peek: "<< test.peek()<< endl; //3
	}
	catch(std::out_of_range& err)
	{
		cout<<err.what()<<endl;
	}

	cout<<endl;
	cout<<"test 2"<<endl;

	Stack<char*> testC;
	try{
		testC.push("alabala");
		cout << "returned value from the top(and removed): " << testC.pop() <<  endl; 
		cout << "returned value from the top(and removed): " << testC.pop() <<  endl;
	}
	catch(std::out_of_range& err)
	{
		cout<<err.what()<<endl;
	}

	cout<<endl;
	cout<<"test 3"<<endl;

	Stack<int> ss;
	try {
		ss.pop();
	} 
	catch(std::out_of_range& err)  
	{
		cout<<err.what()<<endl;
	}

		return 0;
	}



