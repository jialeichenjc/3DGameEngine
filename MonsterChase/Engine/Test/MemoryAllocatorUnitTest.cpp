#include "MemoryAllocatorUnitTest.h"
#include "../MemoryManager/BitArray.h"

#include <assert.h>
#include <algorithm>
#include <vector>
#include "../MemoryManager/FixedSizeAllocator.h"
#include "../MemoryManager/MemoryAllocator.h"
#include "time.h"
#define DEFAULT_ALIGNMENT 4
#define __SHOW_FREE_BLOCKS
#define __SHOW_ALLOCATIONS
#define SUPPORT_ALIGNMENT

bool MemoryAllocator_UnitTest() {
	srand(time(NULL));
	const size_t heap_size = 1024 * 1024;
	const size_t fsa_heap_size = 256 * 256;
	// Get a mem_allocator and create heap (with memory allocated)
	MemoryAllocator *mem_allocator = MemoryAllocator::get_instance();
	mem_allocator->create_heap(heap_size);

	// Get a fixed size allocator and create heap
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	fsa_allocator->create_heap(fsa_heap_size, DEFAULT_ALIGNMENT);

	BitArray *bit_array = BitArray::get_instance(256, false);
	std::vector<void *> fsa_allocated_address;

	if (fsa_allocator == nullptr) {
		return false;
	}
	// Test allocation of 100 allocations of size 16 bytes or smaller
	size_t num_allocations = 0;
	size_t test_alloc_size = 8;
	while (num_allocations < 50) {
		size_t req_size = rand() % test_alloc_size + 1;
		void *ptr = fsa_allocator->alloc_mem(req_size);
		assert(ptr);
		fsa_allocated_address.push_back(ptr);
		num_allocations++;
	}

	while (num_allocations > 10) {
		void *ptr = fsa_allocated_address.back();
		fsa_allocated_address.pop_back();
		bool success = fsa_allocator->free_mem(ptr);
		assert(success);
		num_allocations--;
	}

	if (mem_allocator == nullptr)
		return false;
	
	// Test large allocation
	const size_t large_alloc_size = 256 * 256;
	void* test_ptr1 = mem_allocator->alloc_mem(large_alloc_size);
#ifdef __SHOW_FREE_BLOCKS
	mem_allocator->print_list(mem_allocator->free_mem_bd_list);
#endif

#ifdef __SHOW_ALLOCATIONS
	mem_allocator->print_list(mem_allocator->in_use_bd_list);
#endif
	// free this memory
	bool success = mem_allocator->free_mem(test_ptr1);
	assert(success);
	// Test random sizes of allocation

	std::vector<void *> AllocatedAddresses;

	long	numAllocs = 0;
	long	numFrees = 0;
	long	numCollects = 0;

	bool	done = false;

	// allocate memory of random sizes up to 1024 bytes from the heap manager
	// until it runs out of memory
	do
	{
		const size_t		maxTestAllocationSize = 1024;

		size_t			sizeAlloc = 1 + (rand() & (maxTestAllocationSize - 1));

#ifdef SUPPORT_ALIGNMENT
		const unsigned int	alignments[] = { 4, 8, 16, 32, 64 };

		unsigned int	index = rand() % (sizeof(alignments) / sizeof(alignments[0]));

		unsigned int	alignment = alignments[index];
		// set the corresponding alignment size
		mem_allocator->set_alignment_size(alignment);
		void * pPtr = mem_allocator->alloc_mem(sizeAlloc);
		if (pPtr != NULL) {
			AllocatedAddresses.push_back(pPtr);
			numAllocs++;
		}
#else
		void * pPtr = mem_allocator->alloc_mem(sizeAlloc);
		if (pPtr != NULL) {
			AllocatedAddresses.push_back(pPtr);
			numAllocs++;
		}
#endif // SUPPORT_ALIGNMENT
		// out of memory
		if (pPtr == NULL) {
			const unsigned int freeAboutEvery = 10;
			const unsigned int garbageCollectAboutEvery = 40;

			if (!AllocatedAddresses.empty() && ((rand() % freeAboutEvery) == 0))
			{
				void * pPtr = AllocatedAddresses.back();
				AllocatedAddresses.pop_back();

				bool success = mem_allocator->free_mem(pPtr);
				assert(success);

				numFrees++;
			}

			if ((rand() % garbageCollectAboutEvery) == 0)
			{
				// test garbage collection
				mem_allocator->coalesce_mem();

				numCollects++;
			}
			break;
		}

	} while (numAllocs < 200);

#ifdef __SHOW_FREE_BLOCKS
	printf("After exhausting allocations:\n");
	mem_allocator->print_list(mem_allocator->free_mem_bd_list);
#endif // __SHOW_FREE_BLOCKS

#ifdef __SHOW_ALLOCATIONS
	mem_allocator->print_list(mem_allocator->in_use_bd_list);
#endif // __SHOW_ALLOCATIONS
	printf("\n");

	// now free those blocks in a random order
	if (!AllocatedAddresses.empty())
	{
		// randomize the addresses
		std::random_shuffle(AllocatedAddresses.begin(), AllocatedAddresses.end());

		// return them back to the heap manager
		while (!AllocatedAddresses.empty())
		{
			void * pPtr = AllocatedAddresses.back();
			AllocatedAddresses.pop_back();

			bool success = mem_allocator->free_mem(pPtr);
			assert(success);
		}
	}

#ifdef __SHOW_FREE_BLOCKS
	printf("After freeing allocations:\n");
	mem_allocator->print_list(mem_allocator->free_mem_bd_list); 
#endif // __SHOW_FREE_BLOCKS

#ifdef __SHOW_ALLOCATIONS
	mem_allocator->print_list(mem_allocator->in_use_bd_list);
#endif // __SHOW_ALLOCATIONS

	// do garbage collection
	mem_allocator->coalesce_mem();

#ifdef __SHOW_FREE_BLOCKS
	printf("After garbage allocations:\n");
	mem_allocator->print_list(mem_allocator->free_mem_bd_list);
#endif // __SHOW_FREE_BLOCKS

#ifdef __SHOW_ALLOCATIONS
	mem_allocator->print_list(mem_allocator->in_use_bd_list);
#endif // __SHOW_ALLOCATIONS

	printf("\n");		// do a large test allocation to see if garbage collection worked
	void * pPtr = mem_allocator->alloc_mem(1024);
	assert(pPtr);

	if (pPtr)
	{
		bool success = mem_allocator->free_mem(pPtr);
		assert(success);

	}
	
	// we succeeded

	// clean up
	//bit_array->destroy_instatnce();
	fsa_allocator->destroy_instance();
	mem_allocator->destroy_instance();
	
	return true;
}