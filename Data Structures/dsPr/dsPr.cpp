// DS.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Tests.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



int main()
{
	
	Tests t;
	vector <bool> lst{ t.test1(), t.test2(), t.test3(), t.test4(), t.test5(), t.test6(), t.test7(), 
		t.test8(), t.test9(), t.test10(), t.test11(), t.test12(), t.test13(), t.test14(), t.test15(), t.test16(),
		t.test17(), t.test18(), t.test19(), t.test20(), t.test21()};

	cout << endl;
	size_t pass = 0, fail = 0,count=1;
	for (const auto &func: lst)
	{
		if (func){
			pass++;
			count++;
		}
		else{
			fail++;
			cout << "test" << count << " failed" << endl;
			count++;
		}
	}
	cout << pass << " succeeded " << fail << " failed" << endl;


	//try{
	//	t.test1(); cout << endl;//t.test1: popBack() from empty list throw!
	//	t.test2(); cout << endl;//t.test2: popFront() from empty list throw!
	//	t.test3(); cout << endl;//test 3: pushFront(*) popBack()
	//	t.test4(); cout << endl;//test 4: pushFront(*) popFront()
	//	t.test5(); cout << endl;//test 5: pushBack(*) popBack()
	//	t.test6(); cout << endl;//test 6: pushBack(*) popFront()
	//	t.test7(); cout << endl; //test 7: push order
	//	t.test8(); cout << endl;//test 8: push head and tail
	//	t.test9(); cout << endl;//test 9: insert
	//	t.test10(); cout << endl;//test 10: remove
	//	t.test11(); cout << endl;//test 11 : Sort list
	//	t.test12(); cout << endl;//test 12 : Reverse list
	//	t.test13(); cout << endl; //test 13: list remove last and pushback"
	//	t.test14(); cout << endl;//test 14: list- pushback-> insert at 0 ->pushback
	//	t.test15(); cout << endl;//test 15: Queue pop() from empty
	//	t.test16(); cout << endl;//test 16: Queue push and pop()
	//	t.test17(); cout << endl; //test 17: Queue push, pop, peek  
	//	t.test18(); cout << endl; //test 18: Stack push pop  TODO:
	//	t.test19(); cout << endl;//test 19: Stack pop from empty
	//	t.test20(); cout << endl; //test 12: Queue char* push pop peek  <char*> 
	//	t.test21(); cout << endl; // Queue char*  <char*>
	//	t.test22(); cout << endl; //test 22 Stack push pop  <char*>
	//}
	//catch (std::out_of_range& err)
	//{

	//	cout << err.what() << endl;
	//}
	return 0;
}

