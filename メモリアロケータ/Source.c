#include "MemoryAllocator.h"

int main() {
	Memory M = MemoryAllocate(16 ,sizeof(int));
	MemoryFree(&M);

	return 0;
}