#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct Memory_ {
	void* Memory;
	size_t ElementSize;
	size_t Length;
} Memory;

Memory MemoryAllocate(size_t N, size_t SizeOfElement);
Memory MemoryReAllocate(Memory* Mem, size_t N);
bool MemoryFree(Memory*);