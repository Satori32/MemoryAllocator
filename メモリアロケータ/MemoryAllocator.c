#include <stdlib.h>
#include <memory.h>
#include "MemoryAllocator.h"

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

bool MemoryFree(Memory* In) {
	free(In->Memory);

	In->Memory = NULL;
	In->Length = 0;
	In->ElementSize = 0;
	return true;
}