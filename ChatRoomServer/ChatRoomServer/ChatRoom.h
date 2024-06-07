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
	//�����߽��������ң���Ӳ����ߣ����Ըò�����ת�������������
	void join(chat_participant_ptr participant);
	//�������뿪������������ָ��
	void leave(chat_participant_ptr participant);
	//�����в�����ת����Ϣ
	void deliver(const ChatMessage& msg);

private:
	std::set<chat_participant_ptr> participants_;
	enum { max_recent_msgs = 100 };
	chat_message_queue recent_msgs_;
};
#endif