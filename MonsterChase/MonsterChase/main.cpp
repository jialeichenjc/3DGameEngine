#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <crtdbg.h>
#include <vector>
#include <intrin.h>
#include <Windows.h>
#include <stdint.h>
#include <chrono>
#include <thread> // might not be necessary
#include "Monster.h"
#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryManager/MemoryAllocator.h"
#include "Test/MemoryAllocatorTest.h"
#include "Test/EngineTestSuite.h"
#include "Test/SmartPointerUnitTest.h"
#include "Test/StringPoolUnitTest.h"
#include "MemoryManager/BitArray.h"
#include "GameObject.h"
#include "Test/MemoryAllocatorUnitTest.h"
#include "Test/Matrix4x4UnitTest.h"
#include "MemoryManager/FixedSizeAllocator.h"
#include "CreateGameObject.h"
#include "time.h"
#include "Play.h"
#include "GLib.h"
#include "Game.h"
#include "SmartPointer.h"
#include "PaddleAI.h"
#include "PaddleAI.h"

//typedef std::chrono::high_resolution_clock clock;

void printList(BlockDescriptorList);
void print_bit_array(uint8_t*, size_t);

void * LoadFile(const char * i_pFilename, size_t & o_sizeFile);
GLib::Sprites::Sprite * CreateSprite(const char * i_pFilename);

void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{
#ifdef _DEBUG
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	OutputDebugStringA(Buffer);
#endif // __DEBUG
}

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow) {
#if defined _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	//_CrtSetBreakAlloc(192);
	// test smart pointer
	SmartPointer_UnitTest();
	StringPool_UnitTest();
	Matrix4x4_UnitTest();

	Game::init();
	Game::shut_down();
	//Game::monster_count++;
	// TODO: the following lua call is disabled to fix memory leaks, NEED INVESTIGATION
	//create_game_object("Player.lua");

	MemoryAllocator* test_allocator = MemoryAllocator::get_instance();
	FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();

	auto start = std::chrono::high_resolution_clock::now();

	// Initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600);
	
	//Player *player = new Player();
	//player->init_pos();
	//player->set_name("test player");

	//Monster *monster = new Monster();

	if (bSuccess) {
		GLib::SetKeyStateChangeCallback(TestKeyCallback);

		GLib::Sprites::Sprite *pBluePaddleSprite = CreateSprite("Sprites\\blue-paddle.dds");
		GLib::Sprites::Sprite *pGreenPaddleSprite = CreateSprite("Sprites\\green-paddle.dds");
		GLib::Sprites::Sprite *pBallSprite = CreateSprite("Sprites\\ball.dds");
		GLib::Sprites::Sprite *pCourtSprite = CreateSprite("Sprites\\court.dds");

		bool bQuit = false;

		do {
			GLib::Service(bQuit);

			if (!bQuit) {
				GLib::BeginRendering();
				GLib::Sprites::BeginRendering();
				static GLib::Point2D CourtOffset = { 0.0f, -300.0f };
				GLib::Sprites::RenderSprite(*pCourtSprite, CourtOffset, 0.0f);

			/*	if (player->get_sprite()) {
					static GLib::Point2D offset = { -180.0f, -100.0f };
					GLib::Sprites::RenderSprite(*(player->get_sprite()), offset, 0.0f);
				}

				if (monster->get_sprite()) {
					static GLib::Point2D offset = { 0.0f, -300.0f };
					GLib::Sprites::RenderSprite(*(monster->get_sprite()), offset, 0.0f);
				}*/

				GLib::Sprites::EndRendering();
				GLib::EndRendering();
			}
		} while (bQuit == false);

		// release all the sprites
		if (pBluePaddleSprite) {
			GLib::Sprites::Release(pBluePaddleSprite);
		}

		if (pGreenPaddleSprite) {
			GLib::Sprites::Release(pGreenPaddleSprite);
		}

		if (pCourtSprite) {
			GLib::Sprites::Release(pCourtSprite);
		}

		if (pBallSprite) {
			GLib::Sprites::Release(pBallSprite);
		}

		//
		//if (pPlayer_sprite) {
		//	GLib::Sprites::Release(pPlayer_sprite);
		//}
		//if (pMonster_sprite) {
		//	GLib::Sprites::Release(pMonster_sprite);
		//}
		GLib::Shutdown();
	}
	//delete player;
	//delete monster;

	fsa_allocator->destroy_instance();
	test_allocator->destroy_instance();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
	auto time_elapsed = duration.count();
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

GLib::Sprites::Sprite * CreateSprite(const char * i_pFilename)
{
	//assert(i_pFilename);

	size_t sizeTextureFile = 0;

	// Load the source file (texture data)
	void * pTextureFile = LoadFile(i_pFilename, sizeTextureFile);

	// Ask GLib to create a texture out of the data (assuming it was loaded successfully)
	GLib::Texture * pTexture = pTextureFile ? GLib::CreateTexture(pTextureFile, sizeTextureFile) : nullptr;

	// exit if something didn't work
	// probably need some debug logging in here!!!!
	if (pTextureFile)
		delete[] pTextureFile;

	if (pTexture == nullptr)
		return NULL;

	unsigned int width = 0;
	unsigned int height = 0;
	unsigned int depth = 0;

	// Get the dimensions of the texture. We'll use this to determine how big it is on screen
	bool result = GLib::GetDimensions(pTexture, width, height, depth);
	//assert(result == true);
	//assert((width > 0) && (height > 0));

	// Define the sprite edges
	GLib::Sprites::SpriteEdges	Edges = { -float(width / 2.0f), float(height), float(width / 2.0f), 0.0f };
	GLib::Sprites::SpriteUVs	UVs = { { 0.0f, 0.0f },{ 1.0f, 0.0f },{ 0.0f, 1.0f },{ 1.0f, 1.0f } };
	GLib::RGBA							Color = { 255, 255, 255, 255 };

	// Create the sprite
	GLib::Sprites::Sprite * pSprite = GLib::Sprites::CreateSprite(Edges, 0.1f, Color, UVs);
	if (pSprite == nullptr)
	{
		GLib::Release(pTexture);
		return nullptr;
	}

	// Bind the texture to sprite
	GLib::Sprites::SetTexture(*pSprite, *pTexture);

	return pSprite;
}

void * LoadFile(const char * i_pFilename, size_t & o_sizeFile)
{
	//assert(i_pFilename != NULL);

	FILE * pFile = NULL;

	errno_t fopenError = fopen_s(&pFile, i_pFilename, "rb");
	if (fopenError != 0)
		return NULL;

	//assert(pFile != NULL);

	int FileIOError = fseek(pFile, 0, SEEK_END);
	//assert(FileIOError == 0);

	long FileSize = ftell(pFile);
	//assert(FileSize >= 0);

	FileIOError = fseek(pFile, 0, SEEK_SET);
	//assert(FileIOError == 0);

	uint8_t * pBuffer = new uint8_t[FileSize];
	//assert(pBuffer);

	size_t FileRead = fread(pBuffer, 1, FileSize, pFile);
	//assert(FileRead == FileSize);

	fclose(pFile);

	o_sizeFile = FileSize;

	return pBuffer;
}
