#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include <intrin.h>
#include <Windows.h>

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
#include "Play.h"
#include "GLib.h"

#define HEAP_SIZE 1024 * 1024
#define DEFAULT_ALIGNMENT_SIZE 4

void printList(BlockDescriptorList);
void print_bit_array(uint8_t*, size_t);

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600);

	//MemoryAllocator_UnitTest();
	//play();
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