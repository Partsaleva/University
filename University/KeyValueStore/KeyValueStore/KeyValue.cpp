#include "stdafx.h"
#include "KeyValue.h"
#include <fstream>
#include <string>

	KeyValue::KeyValue() {
		for (size_t i = 0; i < tableSize; i++){
			hashTable[i] = new Data();
		}
	}
	KeyValue::~KeyValue() {
		
		for (int i = 0; i < tableSize; i++){
			
			hashTable[i] = nullptr;
		}
	}

	


	size_t KeyValue::store(std::string data) {	
		writeInFile(data);
		return lineNumber;
	}


	void KeyValue::load(size_t key) {
		if (key < tableSize){
			Data* curr = hashTable[key];
			cout << curr->key << ": " << curr->memoryBlock << endl;
		}
		else {
			cout << key << " was not found in the Table" << endl;
		}
	}

	void KeyValue::loadFile(){
		std::ifstream recordsFile;
		recordsFile.open("records.txt");
		if (!recordsFile.is_open()) {
			std::cerr << "Error opening file" << endl;
		}
		std::string line;		
		while (getline(recordsFile, line)){
			hashTable[index]->key = index;
			hashTable[index]->memoryBlock = line;
			index++;
		}
		recordsFile.close();	
	}

	void KeyValue::erase(size_t key) {
		if (key>=tableSize) {
			cout << key+1 << " was not found in the Table" << endl;
		}
		else{
			hashTable[key]->key = 0;
			hashTable[key]->memoryBlock = "";
			//TODO
		}	
	}

	

	

	void KeyValue::print()const {

		for (size_t i = 0; i < tableSize; i++){
			Data* curr = hashTable[i];
			cout << curr->key << "  :  " << curr->memoryBlock << endl;
			curr = curr->next;
		}			
			cout << endl;
	}
	

	
	void KeyValue::writeInFile(std::string data)
	{
		std::ofstream file("records.txt", std::ios::app);
		if (!file.is_open()) {
			std::cerr << "Error opening file" << endl;
		}			
		file << data << endl;	
		lineNumber++;
		file.close();
	}
