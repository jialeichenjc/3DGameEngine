#pragma once
#include "HashedString.h"
#include "IActorType.h"
namespace MessageSystem {
	typedef void(*MessageHandler_t)(const HashedString & i_Message);
	class IMessageHandler {
	public:
		virtual void HandleMessage(const HashedString & i_Message, IActorType * i_pDetails) = 0;
		~IMessageHandler() {}
	};

	void RegisterMessageHandler(const HashedString & i_Message, MessageHandler_t i_pHandler);
	void DeregisterMessageHandler(const HashedString & i_Message, IMessageHandler * i_pHandler);

	void SendMessage(const HashedString & i_Message, void * i_pMessageDetails);
}

//class MessageSystem
//{
//public:
//	MessageSystem();
//	~MessageSystem();
//};
//
