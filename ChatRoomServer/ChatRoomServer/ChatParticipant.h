#pragma once
#ifndef CHAT_PARTICIPANT
#define CHAT_PARTICIPANT

#include"ChatMessage.hpp"

//�����ࣺ�����ҵĲ�����
class ChatParticipant
{
public:
	virtual ~ChatParticipant();
	virtual void deliver(const ChatMessage& msg) = 0;
};
#endif