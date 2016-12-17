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
	BitArray *bit_arr = BitArray::get_instance(256, false);
	assert(fsa_allocator->alloc_mem(16) != nullptr, "fail to allocate memory");
	unsigned long mask = 0x22;
	unsigned long index;
	unsigned char test_bs_forward = _BitScanForward(&index, mask);

	printf("First set bit is: %d\n", index);
	print_bit_array(bit_arr->get_byte_array(), 256/8);

	uint8_t *test_byte_array = new uint8_t[4];
	test_byte_array[0] = 0x00;
	test_byte_array[1] = 0x14;
	test_byte_array[2] = 0x24; 	
	test_byte_array[3] = 0x00; // test_byte_array == 00000000 00010100 00100100 00000000	
	bit_arr->set_byte_array(test_byte_array);
	assert(bit_arr->get_first_set_byte() == 1, "assert failed");
	assert(bit_arr->get_first_set_bit(test_byte_array[1]) == 2, "assert failed");
	assert(bit_arr->get_set_bit_offset() == 10, "assert failed");
	//printf("\nget_set_bit_offset: %zu\n", bit_arr->get_set_bit_offset());
	uint8_t test_bit = 0x1C; // binary form 0001 1100
	bit_arr->set_bits_to_zero(test_bit, 2, 2);
	//assert(test_bit == 0x00, "assert failed");
	test_bit = 0xF;
	bit_arr->set_bits_to_zero(test_bit, 0, 2);
	//assert(test_bit == 0x10, "assert failed");
	printf("\n set bit %02x\n", test_bit);
	uint8_t test_mask = 0x01;
	printf("\n mask %08x\n", test_mask << 2);
	print_bit_array(test_byte_array, 4);
	mem_allocator->destroy_instance();
	fsa_allocator->destroy_instance();
	bit_arr->destroy_instatnce();
	//delete test_byte_array;
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
		printf("%02x ", p_bits_array[i]);
	}
}