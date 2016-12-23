 #ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <cstddef>
#include "stack.h"

class Allocator
{
	Stack<void *> free_block;
	void *mem;
	std::size_t size;
	std::size_t count;

public:
	Allocator(std::size_t count, std::size_t each_size);
	void *Alloc();
	void Free(void *ptr);
	bool Empty();
	std::size_t Size();
	~Allocator();
};

#endif