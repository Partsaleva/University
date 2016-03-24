#ifndef KEYVALUE_H
#define KEYVALUE_H

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"
#include "Block.h"
#include "Data.h"

using std::endl;
using std::cout;
static size_t lineNumber = -1;
static size_t index = 0;

class KeyValue {

public:

	KeyValue();
	~KeyValue();

	//hash function                                  
	size_t hashFunctionForKey(std::string key);
	//generating key
	std::string keyGenerator(const char* data, const size_t &size);
	size_t store(std::string data);
	void load(size_t key);
	void erase(size_t key);
	void print()const;
	void loadFile();
	void readData(std::ifstream& inputFile, Vector<Data>& dataList);
	void writeInFile(std::string d);
	//-----------------------------private-------------------------------//
private:
	static const size_t tableSize = 19;
	
	Data* hashTable[tableSize];

};

#endif