#include <string>
struct Data {

	Data():key(),memoryBlock(){}
	Data(size_t dataKey, std::string data) :key(dataKey), memoryBlock(data),next(nullptr){	}
	std::string memoryBlock;
	size_t key;
	Data* next;
};