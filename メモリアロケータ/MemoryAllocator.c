#include <stdlib.h>
#include <memory.h>
#include "MemoryAllocator.h"

//MitLicese.
//2019 Yakitori.

#define BYTE unsigned char

Memory MemoryAllocate(size_t N,size_t SizeOfElement ) {
	Memory M = { NULL,0 ,0};

	M.Memory = malloc(N*SizeOfElement);

	if (M.Memory != NULL) {	
		memset(M.Memory, 0, N*SizeOfElement);
		M.Length = N;
		M.ElementSize = SizeOfElement;
	}

	return M;
}

Memory MemoryReAllocate(Memory* Mem,size_t N) {
	void *p = realloc(Mem->Memory,N*Mem->ElementSize);

	if (p != NULL) {	
		//if (p != Mem->Memory) { free(Mem->Memory); }//this is safe??
		Mem->Memory = p;
		Mem->Length = N;
	}

	return *Mem;
}

void* MemoryIndex(Memory* M, size_t Idx) {
	return (Idx < M->Length) ? (((BYTE*)M->Memory) + (M->ElementSize * Idx)) : NULL;
}

bool MemoryFree(Memory* In) {
	free(In->Memory);

	In->Memory = NULL;
	In->Length = 0;
	In->ElementSize = 0;
	return true;
}