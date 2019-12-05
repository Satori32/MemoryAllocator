#include "MemoryAllocator.h"
//#include <crtdbg.h>//ms env only.

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF| _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	Memory M = MemoryAllocate(16 ,sizeof(int));
	Memory B = MemoryReAllocate(&M, 32);
	MemoryFree(&B);

	//_CrtDumpMemoryLeaks();//ms only.

	return 0;
}