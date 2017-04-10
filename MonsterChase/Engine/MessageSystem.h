#pragma once
#include "HashedString.h"
#include "IActorType.h"
namespace MessageSystem {
	typedef void(*MessageHandler_t)(const HashedString & i_Message);

	void RegisterMessageHandler(const HashedString & i_Message, MessageHandler_t i_pHandler);

	class IMessageHandler {
	public:
		virtual void HandleMessage(const HashedString & i_Message, IActorType * i_pDetails) = 0;
		~IMessageHandler() {}
	};
}

//class MessageSystem
//{
//public:
//	MessageSystem();
//	~MessageSystem();
//};
//
