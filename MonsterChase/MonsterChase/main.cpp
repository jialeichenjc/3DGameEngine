#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include <intrin.h>
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryAllocator.h"
#include "MemoryAllocatorTest.h"
#include "EngineTestSuite.h"
#include "BitArray.h"
#include "GameObject.h"
#include "MemoryAllocatorUnitTest.h"
#include "FixedSizeAllocator.h"
#include "time.h"
#define HEAP_SIZE 1024 * 1024
#define DEFAULT_ALIGNMENT_SIZE 4

void printList(BlockDescriptorList);
void print_bit_array(uint8_t*, size_t);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	MemoryAllocator *mem_allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();
	fsa_allocator->create_heap(HEAP_SIZE, DEFAULT_ALIGNMENT_SIZE);
	BitArray *bit_arr = BitArray::get_instance(256, true);
	unsigned long mask = 0x22;
	unsigned long index;
	unsigned char test_bs_forward = _BitScanForward(&index, mask);

	printf("First set bit is: %d\n", index);
	print_bit_array(bit_arr->get_byte_array(), 256/8);


	mem_allocator->destroy_instance();
	fsa_allocator->destroy_instance();
	bit_arr->destroy_instatnce();
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


void print_bit_array(uint8_t *p_bits_array, size_t num_bytes) {
	for (size_t i = 0; i < num_bytes; i++) {
		printf("%08x ", p_bits_array[i]);
	}
}