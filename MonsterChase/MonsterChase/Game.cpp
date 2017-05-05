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
GameObject * pUpperBoundary;
GameObject * pLowerBoundary;
Collidable UpperBound;
Collidable LowerBound;
CollisionHandler Handler1;
CollisionHandler Handler2;
CollisionHandler Handler3;
CollisionHandler Handler4;

uint8_t PlayerMove;
Vector3D PlayerVelocityRight;
Vector3D PlayerVelocityLeft;

void Game::init() {
	test_allocator = MemoryAllocator::get_instance();
	fsa_allocator = FixedSizeAllocator::get_instance();
	pTestPaddle = new PaddlePlayer();
	pTestPaddleLeft = new PaddlePlayer();
	pTestPaddleAI = new PaddleAI();
	pBall = new Ball();
	pCourt = new GameObject();
	pUpperBoundary = new GameObject();
	pLowerBoundary = new GameObject();

	pCourt->SetPosition(Vector3D(0.0f, -300.0f, 0.0f));
	pUpperBoundary->SetPosition(Vector3D(0.0f, 270.0f, 0.0f));
	pLowerBoundary->SetPosition(Vector3D(0.0f, -270.0f, 0.0f));
	UpperBound.SetGameObject(pUpperBoundary);
	LowerBound.SetGameObject(pLowerBoundary);

	pTestPaddle->SetPosition(Vector3D(380.0f, -64.0f, 0.0f));
	pTestPaddle->SetVelocity(PlayerVelocityRight);

	pTestPaddleAI->SetPosition(Vector3D(-380.0f, -100.0f, 0.0f));

	pTestPaddleLeft->SetPosition(Vector3D(-380.0f, -100.0f, 0.0f));
	pTestPaddleLeft->SetVelocity(PlayerVelocityLeft);

	pBall->SetPosition(Vector3D(100.0f, -80.0f, 0.0f));
	pBall->SetVelocity(Vector3D(0.1f, 0.05f, 0.0f));
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
	GLib::Sprites::Sprite *pUpperBoundSprite = Graphics::CreateSprite("Sprites\\blue-paddle.dds");

	pTestPaddle->SetSprite(pGreenPaddleSprite);
	pTestPaddleLeft->SetSprite(pBluePaddleSprite);
	pUpperBoundary->SetSprite(pUpperBoundSprite);
	pCourt->SetSprite(pCourtSprite);
	pBall->SetSprite(pBallSprite);

	pTestPaddle->SetSpriteSize(32.0f, 128.0f, 0.0f);
	pTestPaddleLeft->SetSpriteSize(32.0f, 128.0f, 0.0f);
	pBall->SetSpriteSize(32.0f, 32.0f, 0.0f);
	UpperBound.SetSize(800.0f, 10.0f, 0.0f);
	UpperBound.InitAABB();
	LowerBound.SetSize(800.0f, 10.0f, 0.0f);
	LowerBound.InitAABB();

	pTestPaddle->InitCollidable();
	pTestPaddle->SetBouncy(false);

	pTestPaddleLeft->InitCollidable();
	pTestPaddleLeft->SetBouncy(false);

	pBall->InitCollidable();
	pBall->SetBouncy(true);
	
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
			//Graphics::Render(pUpperBoundary);

			Graphics::Render(pCourt);
		
			pTestPaddle->SetVelocity(PlayerVelocityRight);
			pTestPaddle->MoveByPlayer();

			pTestPaddleLeft->SetVelocity(PlayerVelocityLeft);
			pTestPaddleLeft->MoveByPlayer();

			pBall->MoveWithVelocity();

			Handler1.HandleCollision(pBall->GetCollidable(), LowerBound);
			Handler2.HandleCollision(pBall->GetCollidable(), UpperBound);
			Handler3.HandleCollision(pTestPaddle->GetCollidable(), pBall->GetCollidable());
			Handler4.HandleCollision(pTestPaddleLeft->GetCollidable(), pBall->GetCollidable());
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

	if (pUpperBoundSprite) {
		GLib::Sprites::Release(pUpperBoundSprite);
	}

}

void Game::ShutDown() {
	
	if (pTestPaddle) delete pTestPaddle;
	if (pTestPaddleLeft) delete pTestPaddleLeft;
	if (pTestPaddleAI) delete pTestPaddleAI;
	if (pCourt) delete pCourt;
	if (pBall) delete pBall;
	if (pUpperBoundary) delete pUpperBoundary;

	fsa_allocator->destroy_instance();
	test_allocator->destroy_instance();

}

void Game::TestKeyCallback(unsigned int i_VKeyID, bool bWentDown) {
#ifdef _DEBUG
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	if (i_VKeyID == 0x57 && bWentDown) {
		//PlayerMove = 'W';
		PlayerVelocityLeft = Vector3D(0.0f, 0.1f, 0.0f);
		sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	}
	else if (i_VKeyID == 0x53 && bWentDown) {
		PlayerVelocityLeft = Vector3D(0.0f, -0.1f, 0.0f);
		sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	}
	else if (i_VKeyID == 0x4f && bWentDown) {
		PlayerVelocityRight = Vector3D(0.0f, 0.1f, 0.0f);
	}
	else if (i_VKeyID == 0x4b && bWentDown) {
		PlayerVelocityRight = Vector3D(0.0f, -0.1f, 0.0f);
	}
	else {
		PlayerVelocityRight = Vector3D(0.0f, 0.0f, 0.0f);
		PlayerVelocityLeft = Vector3D(0.0f, 0.0f, 0.0f);
	}

	sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	OutputDebugStringA(Buffer);
#endif // __DEBUG
}