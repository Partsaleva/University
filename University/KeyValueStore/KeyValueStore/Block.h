#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>

class Block
{
public:
	Block();
	Block(const char* data, const size_t &dataSize);
	~Block();
	char* getData();
	size_t getSize();

private:
	char *memoryBlock;
	size_t size;
};

#endif