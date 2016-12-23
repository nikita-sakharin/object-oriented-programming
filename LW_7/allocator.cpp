#include <cmath>
#include "allocator.h"

const static std::size_t START_SIZE = 64u;

typedef unsigned char Byte;

Allocator::Allocator(std::size_t hint_count, std::size_t each_size)
{
	size = each_size;
	if (hint_count)
	{
		count = static_cast<std::size_t>(pow(2.0, ceil(log2(hint_count))));
	}
	else
	{
		count = START_SIZE;
	}
	mem = new Byte[count * size];
	for (size_t i = 0u; i < count; ++i)
	{
		free_block.Push(static_cast<void *>(static_cast<Byte *>(mem) + i * size));
	}
}

void *Allocator::Alloc()
{
	if (free_block.Empty())
	{
		return nullptr;
	}

	void *result = free_block.Front();
	free_block.Pop();

	return result;
}

void Allocator::Free(void *ptr)
{
	free_block.Push(ptr);
}

bool Allocator::Empty()
{
	return free_block.Empty();
}

std::size_t Allocator::Size()
{
	return free_block.Size();
}

Allocator::~Allocator()
{
	delete [] static_cast<Byte *>(mem);
}