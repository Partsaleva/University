#include "stdafx.h"
#include <iostream>

#include "Vector.h"

using std::cout;
using std::endl;

 


class Set{
	typedef size_t index_type;
public:
	Set(){
		size = 0;
		capacity = 1;
		v = new Vector();
		vec = *v;
	}

	

	Set(const Set &orig){
		copy(orig);
	}
	
	void add(const int &value){
		if (!found(value)){
			if (size == capacity){
				doubleSize();
			}			
			vec.add(value);					
			size++;
		}
	}

	bool found(const int &value){
		for (index_type i = 0; i < size; ++i)
		{
			if (value == vec.get(i)){
				return true;
			}
		}
		return false;
	}


	

	void remove(const int& value)
	{
		
		for (index_type i = 0; i < size; ++i) {
			if (vec.get(i) == value) {
				vec.remove(i);
				break;
			}
		}
		--size;
	}


	Set setUnion(const Set &t){
		Set result(*this);
		
		for (index_type i = 0; i < t.size; ++i){
			result.add(t.get(i));
		}
		
		return result;
	}


	// : returns the intersection of sets S and T.
	Set intersection(const Set &t){
		Set result(*this);
			
		index_type first1 = result.vec.begin();
		index_type last1 = result.vec.end();

		index_type first2 = t.vec.begin();
		index_type last2 = t.vec.end();

		while (first1 != last1 && first2!= last2)
		{
			if (result.get(first1) == t.get(first2)){
				++first1; ++first2;
			}
			else if (result.get(first1) < t.get(first2)) {
				result.remove(result.get(first1));
				 --last1;
			}
			else {
				++first2;				
			}
		}
		return result;
	}

	
	// : returns the difference of sets S and T.
	Set difference(const Set &t){
		Set result(*this);

		index_type first1 = result.vec.begin();
		index_type last1 = result.vec.end();

		index_type first2 = t.vec.begin();
		index_type last2 = t.vec.end();

		while (first1 != last1 && first2 != last2)
		{
			if (result.get(first1) < t.get(first2)){
				++first1;
			}
			else if (result.get(first1) > t.get(first2)) {
				++first2;
			}
			else {
				result.remove(result.get(first1));
				++first1; ++first2;
			}
		}
		return result;
	}

	// : a predicate that tests whether the set S is a subset of set T.
	bool isSubset(const Set &t){
		Set result(*this);
	
		index_type count = 0;

		index_type first1 = result.vec.begin();
		index_type last1 = result.vec.end();

		index_type first2 = t.vec.begin();
		index_type last2 = t.vec.end();

		while (first1 != last1 && first2 != last2)
		{
			if (result.get(first1) < t.get(first2)){
				++first1;
			}
			else if (result.get(first1) > t.get(first2)) {
				++first2;
			}
			else {
				++count;
				++first1; ++first2;
			}
		}
		if (count == result.size)
		{
			return true;
		}
		else return false;
		
	}
		
	const void print(){
		vec.print();
	}
	//-------------------private----------------------//
private:
	index_type capacity;
	index_type size;
	Vector *v;
	Vector vec;

	void doubleSize(){
		capacity *= 2;

	}

	void copy(const Set &orig){
		size = orig.size;
		capacity = orig.capacity;
		vec = orig.vec;
	}


	inline index_type get(index_type index)const{
		return vec.get(index);
	}
	
};

int main(){

	Set s,s1,s2,s3,s4,s5;
	
		
	s.add(2); s.add(3); s.add(4); s.add(5); s.add(6); s.add(6); s.add(11);
	s1.add(7); s1.add(8); s1.add(9); s1.add(2); s1.add(10); s1.add(11);	s1.add(4);
	s.print();	
	s1.print();
	

	
	s2=s.setUnion(s1);
	s2.print();

	s3 = s.intersection(s1);
	s3.print();

	s4=s.difference( s1);
	s4.print();

	cout << s.isSubset(s2)<<endl;
//	


	/*Set s, s1, s2;
	for (int i = 0; i < 20; ++i) {
	s.add(i);
	}
	s1.add(10);
	s2 = s.difference(s1);
	s2.print();*/
	return 0;
}