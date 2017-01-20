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
	// Initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600);

	if (bSuccess) {
		GLib::SetKeyStateChangeCallback(TestKeyCallback);

		GLib::Sprites::Sprite *pMonster = CreateSprite("data\\BadGuy.dds");
		GLib::Sprites::Sprite *pPlayer = CreateSprite("data\\GoodGuy.dds");

		bool bQuit = false;

		do {
			GLib::Service(bQuit);

			if (!bQuit) {
				GLib::BeginRendering();
				GLib::Sprites::BeginRendering();

				if (pPlayer) {
					static GLib::Point2D offset = { -180.0f, -100.0f };
					GLib::Sprites::RenderSprite(*pPlayer, offset, 0.0f);
				}

				if (pMonster) {
					static GLib::Point2D offset = { 180.0f, -100.0f };
					GLib::Sprites::RenderSprite(*pMonster, offset, 0.0f);
				}

				GLib::Sprites::EndRendering();
				GLib::EndRendering();
			}
		} while (bQuit == false);
		
		if (pPlayer) {
			GLib::Sprites::Release(pPlayer);
		}
		if (pMonster) {
			GLib::Sprites::Release(pMonster);
		}
		GLib::Shutdown();
	}

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
