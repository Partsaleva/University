#include "stdafx.h"
#include "Block.h"


Block::Block() :memoryBlock(), size(){}

Block::Block(const char* data, const size_t &dataSize){
	size = dataSize;
	memoryBlock = new char[size];
	strcpy_s(memoryBlock, size, data);
}

Block::~Block(){
	delete[] memoryBlock;
}

char* Block::getData(){
	return this->memoryBlock;
}

size_t Block::getSize(){
	return this->size;
}

