#pragma once
#ifndef CHAT_ROMM
#define CHAT_ROMM

#define  _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include "boost/asio.hpp"
#include"ChatMessage.hpp"
#include"ChatSession.h"
typedef std::deque<ChatMessage> chat_message_queue;
typedef std::shared_ptr<ChatParticipant> chat_participant_ptr;

class ChatRoom
{
public:
	//参与者进入聊天室，添加参与者，并对该参与者转发聊天室最近的
	void join(chat_participant_ptr participant);
	//参与者离开，擦除参与者指针
	void leave(chat_participant_ptr participant);
	//对所有参与者转发消息
	void deliver(const ChatMessage& msg);

private:
	std::set<chat_participant_ptr> participants_;
	enum { max_recent_msgs = 100 };
	chat_message_queue recent_msgs_;
};
#endif