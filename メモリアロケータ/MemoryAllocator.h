#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct Memory_ {
	void* Memory;
	size_t ElementSize;
	size_t Length;
} Memory;

Memory MemoryAllocate(size_t N,size_t OneSize);
bool MemoryFree(Memory*);