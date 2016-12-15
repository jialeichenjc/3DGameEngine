#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryAllocator.h"
#include "MemoryAllocatorTest.h"
#include "EngineTestSuite.h"
#include "BitArray.h"
#include "GameObject.h"
#include "time.h"

void printList(BlockDescriptorList);
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	MemoryAllocator* allocator = MemoryAllocator::get_instance();
	printf("size of memory allocator is %zu", sizeof(*allocator));
	//BitArray bit_array_test((size_t)256, false);
	/*
	srand((unsigned int)time(NULL));
	printf("\n\n-------------TEST ALLOCATION-------------\n");
	for (int i = 0; i < 100; i++) {
		size_t requested_size = rand() % 100 + 1;
		printf("\nallocating %zu bytes of memory\n", requested_size);
		allocator->alloc_mem(requested_size);
	}

	printf("\n\n>>>>>>memory in use\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);

	printf("\n\n-------------TEST FREE-------------\n");
	for (size_t i = 0; i < 100; i++) {
		size_t requested_size = rand() % 100 + 1;
		char *test_ptr = static_cast<char*> (allocator->alloc_mem(requested_size));
		allocator->free_mem(test_ptr);
	}
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);
	
	printf("\n\n-------------TEST COALESCE-------------\n");
	allocator->coalesce_mem();
	printf("\n\n>>>>>>memory in use:\n");
	printList(allocator->in_use_bd_list);
	printf("\n\n>>>>>>free memory in allocator\n");
	printList(allocator->free_mem_bd_list);
	*/
	allocator->destroy_instance();
	return 0;
}

void printList(BlockDescriptorList list) {
	if (list.head == NULL) {
		return;
	}
	else {
		BlockDescriptor *curr = list.head;
		while (curr != NULL) {
			printf("\nsize of block descriptor is %zu and the memory pointer is %p\n", 
				curr->block_size, curr->block_base_ptr);
			curr = curr->next_bd;
		}
		printf("size of block list is %zu", list.size);
	}
}