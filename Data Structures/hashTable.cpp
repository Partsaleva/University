// Hash.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

typedef size_t index_type;

class Hash {

public:

	Hash() {
		for (index_type i = 0; i < tableSize; i++){
			hashTable[i] = new Data();
		}
	}
	~Hash() {
		Data* curr = nullptr;
		Data* prev = nullptr;

		for (int i = 0; i < tableSize; i++){
			prev = hashTable[i];

			while (prev != nullptr){

				curr = prev->next;
				delete prev;
				prev = curr;
			}
			hashTable[i] = nullptr;
		}
	}

	//hash function                                     T
	index_type hashFunction(string key) {
		index_type hash = 0;
		index_type index;

		index_type end = key.length();

		for (index_type i = 0; i < end; i++)
		{
			hash = hash + static_cast<int>(key[i]);
			//hash=(hash << 4) ^ (hash >> 8) ^ (static_cast<int>(key[i]));		
		}
		
		index = hash% tableSize;
		return index;
	}


	void addData(string name, index_type phone) {

		index_type index = hashFunction(name);
		if (hashTable[index]->name == "") {

			hashTable[index]->name = name;
			hashTable[index]->phone = phone;
		}
		else {
			Data* curr = hashTable[index];
			Data* newData = new Data(name, phone);
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = newData;
		}
	}


	void findPhoneNumber(string name) {
		index_type index = hashFunction(name);
		bool found = false;
		Data* curr = hashTable[index];

		while (curr != nullptr) {
			if (curr->name == name)
			{
				found = true;
				cout << curr->name << ": " << curr->phone << endl;
			}
			curr = curr->next;
		}
		if (found == false) {
			cout << name << " was not found in the Table" << endl;
		}
	}

	void removeData(string name) {
		index_type index = hashFunction(name);

		Data* del;

		//case 1: empty
		if (hashTable[index]->name == "") {
			cout << name << "was not found in the Table" << endl;
		}
		//case 2: only 1
		else if (hashTable[index]->name == name && hashTable[index]->next == nullptr) {
			hashTable[index]->name = "";
			hashTable[index]->phone = 0;
		}
		//case 3: it is first but there  are more itemes
		else if (hashTable[index]->name == name) {
			del = hashTable[index];
			hashTable[index] = hashTable[index]->next;
			delete del;
		}
		//case 4: first item is not a match
		else {
			Data* prev = hashTable[index];
			Data* curr = hashTable[index]->next;

			while (curr != nullptr && curr->name != name)
			{
				prev = curr;
				curr = curr->next;

			}
			if (curr == nullptr) {
				cout << name << " was not found in the Table" << endl;
			}
			else {
				del = curr;
				prev->next = curr->next;
				delete del;
			}
		}
	}




	void print() {
		for (index_type i = 0; i < tableSize; i++)
		{
			cout << "index: " << i << endl;
			Data* curr = hashTable[i];
			if (curr->name == ""){
				cout << curr->name << endl;
			}
			else{
				while (curr != nullptr) {
					cout << curr->name << "  :  " << curr->phone << endl;
					curr = curr->next;
				}
			}
			cout << endl;
		}
	}


	//-----------------------------private-------------------------------//
private:
	static const index_type tableSize = 19;

	struct Data {
		string name;
		index_type phone;
		Data* next;
		Data() :name(), phone(), next(nullptr) {}
		Data(const string &name, const index_type &phone) :name(name), phone(phone), next(nullptr) {}
	};

	Data* hashTable[tableSize];


};


int main()
{
	Hash hashT;
	//index_type index=hashT.hashFunction("bla ba lala");
	//cout << index << endl;
	hashT.addData("Mariana", 86457987); hashT.addData("Ani", 86413577); hashT.addData("Dida", 86456875);
	hashT.addData("Vili", 86478996); hashT.addData("Ivan", 56451567); hashT.addData("Georgi", 86555577);
	hashT.addData("Petyr", 865485526); hashT.addData("Nikola", 86516545); hashT.addData("Kalin", 84564155);
	hashT.addData("Maria", 86457987); hashT.addData("Anita", 86413577); hashT.addData("Dido", 86456875);
	hashT.addData("Viliana", 86478992); hashT.addData("Ivana", 56451567); hashT.addData("Gergana", 8655557);
	hashT.addData("Petq", 865485526); hashT.addData("Nikolina", 86516545); hashT.addData("Kalina", 84564155);
    hashT.print();
	hashT.findPhoneNumber("gaga");
	hashT.removeData("Petyr");//1 name-  (index 0)
	hashT.removeData("Kalin");//first name (index 1)
	hashT.removeData("Nikolina");//second name (index 4)
	hashT.print();
	return 0;
}

