#pragma once
#include "GLib.h"
#include "MemoryManager/MemoryAllocator.h"
#include "MemoryManager/FixedSizeAllocator.h"
namespace Graphics {

	void initialize(HINSTANCE i_hInstance, int i_nCmdShow) {

	}

	void render(HINSTANCE i_hInstance, int i_nCmdShow) {
		//MemoryAllocator* test_allocator = MemoryAllocator::get_instance();
		//FixedSizeAllocator *fsa_allocator = FixedSizeAllocator::get_instance();

		//// Initialize GLib
		//bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600);
		//Player *player = new Player();
		//player->init_pos();
		//player->set_name("test player");

		//Monster *monster = new Monster();


		//if (bSuccess) {
		//	GLib::SetKeyStateChangeCallback(TestKeyCallback);

		//	GLib::Sprites::Sprite *pMonster_sprite = CreateSprite("data\\BadGuy.dds");
		//	GLib::Sprites::Sprite *pPlayer_sprite = CreateSprite("data\\GoodGuy.dds");
		//	player->set_sprite(pPlayer_sprite);
		//	monster->set_sprite(pMonster_sprite);

		//	bool bQuit = false;

		//	do {
		//		GLib::Service(bQuit);

		//		if (!bQuit) {
		//			GLib::BeginRendering();
		//			GLib::Sprites::BeginRendering();

		//			if (player->get_sprite()) {
		//				static GLib::Point2D offset = { -180.0f, -100.0f };
		//				GLib::Sprites::RenderSprite(*(player->get_sprite()), offset, 0.0f);
		//			}

		//			if (monster->get_sprite()) {
		//				static GLib::Point2D offset = { 180.0f, -100.0f };
		//				GLib::Sprites::RenderSprite(*(monster->get_sprite()), offset, 0.0f);
		//			}

		//			GLib::Sprites::EndRendering();
		//			GLib::EndRendering();
		//		}
		//	} while (bQuit == false);

		//	if (pPlayer_sprite) {
		//		GLib::Sprites::Release(pPlayer_sprite);
		//	}
		//	if (pMonster_sprite) {
		//		GLib::Sprites::Release(pMonster_sprite);
		//	}
		//	GLib::Shutdown();
		//}
	}

	void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
	{
	#ifdef _DEBUG
		const size_t	lenBuffer = 65;
		char			Buffer[lenBuffer];

		sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
		OutputDebugStringA(Buffer);
	#endif // __DEBUG
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
}