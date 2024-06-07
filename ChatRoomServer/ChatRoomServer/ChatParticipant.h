#pragma once
#ifndef CHAT_PARTICIPANT
#define CHAT_PARTICIPANT

#include"ChatMessage.hpp"

//抽象类：聊天室的参与者
class ChatParticipant
{
public:
	virtual ~ChatParticipant();
	virtual void deliver(const ChatMessage& msg) = 0;
};
#endif