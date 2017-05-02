#pragma once
#define DEFAULT_MONSTER_SIZE 4
#define DEFAULT_PLAYER_NAME "Player1"
#define DEFAULT_COLLIDABLE_SIZE 10
#include "MemoryManager/MemoryAllocator.h"
#include "Physics\Collidable.h"
#include "PaddleAI.h"
#include "PaddlePlayer.h"
#include "Ball.h"
#include <stdint.h>

namespace Game {


	void init();
	void render(GameObject *);
	void run();
	void ShutDown();
	void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown);
}
