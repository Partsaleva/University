#include "stdafx.h"
#include "Tests.h"


bool Tests::test1(){
	List<int> l;
	cout << "test1: popBack() from empty list throw!" << endl;
	try {
		l.popBack();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		return true;
	}
	return false;
}

bool Tests::test2(){
	List<int> l;
	cout << "test2: popFront() from empty list throw!" << endl;
	try {
		l.popFront();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		return true;
	}
	return false;
}

bool Tests::test3()
{
	cout << "test 3: pushFront(*) popBack()" << endl;
	List<int> list1;	
	list1.pushFront(42);
	if (list1.popBack() != 42){
		return false;
	}
	else{
		return true;
	}
}

bool Tests::test4()
{
	cout << "test 4: pushFront(*) popFront()" << endl;
	List<int> list1;
	
	list1.pushFront(42);
	if (list1.popFront() != 42){
		return false;
	}
	else{
		return true;
	}
}

bool Tests::test5(){
	cout << "test 5: pushBack(*) popBack()" << endl;
	List<int> list2;
	
	list2.pushBack(43);
	if (list2.popBack() != 43){
		return false;
	}
	else
		return true;
	
}

bool Tests::test6(){
	cout << "test 6: pushBack(*) popFront()" << endl;
	List<int> list2;	
	list2.pushBack(43);
	if (list2.popFront() != 43){
		return false;
	}
	else
		return true;
	
}

bool Tests::test7(){
	cout << "test 7: push order" << endl;
	List<int> list;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushFront(4);
		list.pushFront(5);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		//test
		if (list.popFront() != 7) return false;
		if (list.popFront() != 5) return false;
		if (list.popFront() != 4) return false;
		if (list.popFront() != 1) return false;
		if (list.popFront() != 2) return false;
		if (list.popFront() != 3) return false;
		cout << endl;
		return true;	
}

bool Tests::test8(){
	cout << "test 8: push head and tail" << endl;
	List<int> list;
	
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushFront(4);
	list.pushFront(5);
	list.pushFront(7);
	cout << "print: ";  list.print(); cout << endl;
	list.popFront();
	cout << "print: ";  list.print(); cout << endl;
	list.popBack();
	cout << "print: ";  list.print(); cout << endl;
	list.pushFront(3);
	cout << "print: ";  list.print(); cout << endl;
	list.pushBack(9);
	cout << "print: ";  list.print(); cout << endl;
	if (list.popFront() != 3) return false;
	if (list.popBack() != 9) return false;
	cout << endl;
	return true;
}

bool Tests::test9(){
	cout << "test 9: insert" << endl;
	List<int> list;
	
		list.insert(0, 9);
		cout << "print: ";  list.print(); cout << endl;
		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushFront(4);
		list.pushFront(5);
		list.pushFront(7);
		cout << "print: ";  list.print(); cout << endl;
		list.insert(0, 6);
		cout << "print: ";  list.print(); cout << endl;
		cout << "size: " << list.listSize() << endl;
		list.insert(list.listSize(), 5);
		cout << "print: ";  list.print(); cout << endl;
		cout << "size" << list.listSize() << endl;
		list.insert(3, 1);
		cout << "print: ";  list.print(); cout << endl;
		//test
		if (list.popFront() != 6) return false;
		if (list.popBack() != 5) return false;
		if (list.popFront() != 7) return false;
		if (list.popBack() != 3) return false;
		cout << endl;
		return true;
	
}

bool Tests::test10(){
	cout << "test 10: remove" << endl;
	List<int> list;
	
	list.pushBack(1);
	list.pushFront(4);
	list.pushBack(2);
	list.pushFront(5);
	list.pushBack(3);
	list.pushFront(7);
	cout << "print: ";  list.print(); cout << endl;
	list.remove(4);
	cout << "print: ";  list.print(); cout << endl;
	//list.remove(6);
	//cout << "print: ";  list.print(); cout << endl;
	list.remove(7);
	cout << "print: ";  list.print(); cout << endl;
	list.remove(3);
	cout << "print: ";  list.print(); cout << endl;
	//test
	if (list.popFront() != 5) return false;
	if (list.popFront() != 1) return false;
	if (list.popFront() != 2) return false;
	cout << endl;
	return true;
	
}

bool Tests::test11(){
	cout << "test 11 : Sort list" << endl;
	List<int>r;
	r.sort();
	cout << "sort empty: "; r.print(); cout << endl;
	r.pushBack(7);
	cout << "sort one: "; r.sort();
	r.print(); cout << endl;
	r.pushBack(1);
	r.pushBack(3);
	r.pushBack(5);
	r.pushBack(2);
	r.pushBack(4);
	cout << "original list: "; r.print(); cout << endl;
	cout << "sorted list: "; r.sort(); r.print(); cout << endl;
	r.pushBack(1);
	r.print(); cout << endl;
	r.pushFront(9);
	r.print(); cout << endl;
	r.sort();
	r.print(); cout << endl;
	r.popFront();
	r.print(); cout << endl;
	r.popBack();
	r.print(); cout << endl;
	r.sort();
	cout << endl;
	//test
	if (r.popFront() != 1) return false;
	if (r.popFront() != 2) return false;
	if (r.popFront() != 3) return false;
	if (r.popFront() != 4) return false;
	if (r.popFront() != 5) return false;
	if (r.popFront() != 7) return false;
	cout << endl;
	return true;
}

bool Tests::test12(){
	cout << "test 12 : Reverse list" << endl;
	List<int>n;
	n.pushBack(1);
	n.pushBack(2);
	n.pushBack(3);
	n.pushBack(4);
	n.pushBack(5);
	n.print(); cout << endl;
	n.reverse();
	n.print(); cout << endl;
	n.pushBack(6);
	n.print(); cout << endl;
	n.pushFront(0);
	n.print(); cout << endl;
	n.popBack();
	n.print(); cout << endl;
	n.popFront();
	n.print(); cout << endl;
	cout << endl;
	//test
	if (n.popFront() != 5) return false;
	if (n.popFront() != 4) return false;
	if (n.popFront() != 3) return false;
	if (n.popFront() != 2) return false;
	if (n.popFront() != 1) return false;
	cout << endl;
	return true;
	
}

bool Tests::test13(){
	cout << "test 13: list remove last and pushback" << endl;
	List<int> l;
	l.pushBack(1);
	l.pushBack(2);
	l.remove(2);
	l.pushBack(3);
	l.print(); cout << endl;
	cout << endl;
	if (l.popFront() != 1) return false;
	if (l.popFront() != 3) return false;
	cout << endl;
	return true;
}

bool Tests::test14(){
	cout << "test 14: list- pushback-> insert at 0 ->pushback" << endl;
	List<int> m;
	m.pushBack(2);
	m.insert(0, 1);
	m.pushBack(3);
	m.print(); cout << endl;
	cout << endl;
	//test
	if (m.popFront() != 1) return false;
	if (m.popFront() != 2) return false;
	if (m.popFront() != 3) return false;
	cout << endl;
	return true;
}
bool Tests::test15(){
	cout << "test 15: Queue pop() from empty" << endl;
	Queue <int> q;
	try {
		q.pop();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		return true;
	}
	return false;

}


bool Tests::test16(){
	cout << "test 16: Queue push and pop() " << endl;
	Queue <int> qq;
	qq.push(22);
	if (qq.pop() != 22) { return false; 
	} else
	return true;
	cout << endl;
}


bool Tests::test17(){
	cout << "test 17: Queue push, pop, peek " << endl;
	Queue<int>test;
	test.push(1);
	test.push(2); test.push(3); test.push(4);
	test.print();  cout << endl;
	cout << "size: " << test.size() << endl;
	cout << "pop:" << test.pop() << endl;
	test.print();  cout << endl;
	cout << "size: " << test.size() << endl;
	cout << "pop:" << test.pop() << endl;;
	cout << "pop:" << test.pop() << endl;;
	cout << "Peek: " << test.peek() << endl;
	//test
	if (test.pop() != 4) return false;
	cout << endl;
	return true;

}

bool Tests::test18(){
	cout << "test 18: Stack push pop" << endl;
	Stack<int> stackTest;
	stackTest.push(1);
	stackTest.push(2);
	stackTest.push(3);
	stackTest.push(4);
	stackTest.print();
	cout << "size: " << stackTest.size() << endl; //  4 3 2 1 size: 4
	cout << "returned value from the head(and removed): " << stackTest.pop() << endl; // 4
	stackTest.print();
	cout << "size: " << stackTest.size() << endl; //  3 2 1 size: 3
	cout << "Peek: " << stackTest.peek() << endl; //3
	stackTest.print();
	//test
	if (stackTest.pop() != 3) return false;
	if (stackTest.pop() != 2) return false;
	if (stackTest.pop() != 1) return false;
	cout << endl;
	return true;
}

bool Tests::test19(){
	cout << "test 19: Stack pop from empty" << endl;
	Stack<int> ss;
	try {
		ss.pop();
	}
	catch (std::out_of_range& e) {
		cout << e.what() << endl;
		return true;
	}
	return false;
	
}

bool Tests::test20(){
	cout << "test 20: Queue char* push pop peek" << endl;
	Queue<char*>testChar;
	
		testChar.push("a");
		testChar.push("b"); testChar.push("c"); testChar.push("d");
		testChar.print();  cout << endl;

		cout << "size: " << testChar.size() << endl;
		cout << "pop: " << testChar.pop() << endl;
		testChar.print();  cout << endl;
		cout << "size: " << testChar.size() << endl;
		cout << "Peek: " << testChar.peek() << endl;;
		cout << endl;
		if (testChar.pop() != "b") return false;
		if (testChar.pop() != "c") return false;
		if (testChar.pop() != "d") return false;
		cout << endl;
		return true;

}

bool Tests::test21(){
	cout << "test 21: Queue char*" << endl;
	Queue<char*> testC;
	try{
		testC.push("alabala");
		cout << "pop: " << testC.pop() << endl;
		cout << "pop: " << testC.pop() << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
		return true;
	}
	cout << endl;
	return false;
}

bool Tests::test22(){
	cout << "test 22 Stack push pop" << endl;
	Stack<char*> testS;
	try{
		testS.push("alabala");
		cout << "returned value from the head(and removed): " << testS.pop() << endl;
		cout << "returned value from the head(and removed): " << testS.pop() << endl;
	}
	catch (std::out_of_range& err)
	{
		cout << err.what() << endl;
		return true;
	}

	cout << endl;
	return false;
}