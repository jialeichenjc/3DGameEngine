#include "Player.h"
#include "MonsterController.h"
#include "Debug.h"
#include "MemoryManager/MemoryAllocator.h"
#include "Test/MemoryAllocatorTest.h"
#include "Test/EngineTestSuite.h"
//#include "BitArray.h"
//#include "GameObject.h"
//#include "MemoryAllocatorUnitTest.h"
//#include "FixedSizeAllocator.h"
//#include "time.h"
#include "Game.h"
#include "Graphics.h"
#include "GLib.h"
#include "GamePhysics.h"

MemoryAllocator* test_allocator;
FixedSizeAllocator *fsa_allocator;
PaddlePlayer * pTestPaddle;
PaddlePlayer * pTestPaddleLeft;
PaddleAI * pTestPaddleAI;
Ball * pBall;

GameObject * pCourt;
uint8_t PlayerMove;

void Game::init() {
	test_allocator = MemoryAllocator::get_instance();
	fsa_allocator = FixedSizeAllocator::get_instance();
	pTestPaddle = new PaddlePlayer();
	pTestPaddleLeft = new PaddlePlayer();
	pTestPaddleAI = new PaddleAI();
	pBall = new Ball();
	pCourt = new GameObject();

	pCourt->SetPosition(Vector3D(0.0f, -300.0f, 0.0f));

	pTestPaddle->SetPosition(Vector3D(380.0f, -100.0f, 0.0f));
	pTestPaddleAI->SetPosition(Vector3D(-380.0f, -100.0f, 0.0f));
	pTestPaddleLeft->SetPosition(Vector3D(-380.0f, -100.0f, 0.0f));
	pBall->SetPosition(Vector3D(0.0f, -80.0f, 0.0f));
	pBall->SetVelocity(Vector3D(0.1f, -0.05f, 0.0f));
}

void Game::run(){
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	unsigned int input_key = 0;
	TestKeyCallback(input_key, true);

	GLib::Sprites::Sprite *pBluePaddleSprite = Graphics::CreateSprite("Sprites\\blue-paddle.dds");
	GLib::Sprites::Sprite *pGreenPaddleSprite = Graphics::CreateSprite("Sprites\\green-paddle.dds");
	GLib::Sprites::Sprite *pBallSprite = Graphics::CreateSprite("Sprites\\ball.dds");
	GLib::Sprites::Sprite *pCourtSprite = Graphics::CreateSprite("Sprites\\court.dds");
	pTestPaddle->SetSprite(pGreenPaddleSprite);
	pTestPaddleLeft->SetSprite(pBluePaddleSprite);
	//pTestPaddleAI->SetSprite(pBluePaddleSprite);
	pCourt->SetSprite(pCourtSprite);
	pBall->SetSprite(pBallSprite);

	pTestPaddle->SetSpriteSize(32.0f, 128.0f, 0.0f);
	pTestPaddleLeft->SetSpriteSize(32.0f, 128.0f, 0.0f);
	pBall->SetSpriteSize(32.0f, 32.0f, 0.0f);

	pTestPaddle->InitCollidable();
	pTestPaddleLeft->InitCollidable();
	pBall->InitCollidable();
	
	bool bQuit = false;

	do {
		GLib::Service(bQuit);
		if (!bQuit) {
			GLib::SetKeyStateChangeCallback(TestKeyCallback);
			Graphics::BeginRendering();

			Graphics::Render(pTestPaddle->GetGameObject());
			//Graphics::Render(pTestPaddleAI->GetGameObject());
			Graphics::Render(pTestPaddleLeft->GetGameObject());
			Graphics::Render(pBall->GetGameObject());

			Graphics::Render(pCourt);

			pTestPaddle->MoveByPlayer(PlayerMove);
			pBall->MoveWithVelocity();
			Collision::HandleCollision(pTestPaddle->GetCollidable(), pBall->GetCollidable());
			Collision::HandleCollision(pTestPaddleLeft->GetCollidable(), pBall->GetCollidable());

			Graphics::EndRendering();

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

}

void Game::ShutDown() {
	
	if (pTestPaddle) delete pTestPaddle;
	if (pTestPaddleLeft) delete pTestPaddleLeft;
	if (pTestPaddleAI) delete pTestPaddleAI;
	if (pCourt) delete pCourt;
	if (pBall) delete pBall;

	fsa_allocator->destroy_instance();
	test_allocator->destroy_instance();

}

void Game::TestKeyCallback(unsigned int i_VKeyID, bool bWentDown) {
#ifdef _DEBUG
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	if (i_VKeyID == 0x57 && bWentDown) {
		PlayerMove = 'W';
		sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	}
	else if (i_VKeyID == 0x53 && bWentDown) {
		PlayerMove = 'S';
		sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	}
	else {
		PlayerMove = 0;
	}

	sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	OutputDebugStringA(Buffer);
#endif // __DEBUG
}