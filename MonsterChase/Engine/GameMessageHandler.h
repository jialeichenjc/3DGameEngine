#pragma once
#include "MessageSystem.h"
#include "ActorInfo.h"
class GameMessageHandler : public MessageSystem::IMessageHandler
{
public:
	GameMessageHandler();
	void HandleMessage(const HashedString & i_Message, ActorInfo::ActorType i_ActorType);
	~GameMessageHandler();
};

