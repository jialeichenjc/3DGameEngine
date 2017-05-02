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
#include "Graphics.h"

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow) {
#if defined _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Game::init();

	auto start = std::chrono::high_resolution_clock::now();

	// Initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600);

	if (bSuccess) {
		
		Game::run();
	
		GLib::Shutdown();
		Game::ShutDown();
	}
	return 0;
}
