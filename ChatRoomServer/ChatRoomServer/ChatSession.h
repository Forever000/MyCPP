#pragma once
#ifndef CHAT_SESSION
#define CHAT_SESSION

#define  _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include "boost/asio.hpp"
#include"ChatParticipant.h"
#include"ChatRoom.h"
class ChatRoom;

using namespace std;
using boost::asio::ip::tcp;

typedef std::deque<ChatMessage> chat_message_queue;
typedef std::shared_ptr<ChatParticipant> chat_participant_ptr;

class ChatSession: 
	public ChatParticipant, 
	public std::enable_shared_from_this<ChatSession>
{
public:
	ChatSession(tcp::socket socket, ChatRoom &room);
	void start();
	//将最近的所有消息收集完毕之后转发
	void deliver(const ChatMessage& msg);

private:
	void do_read_header();
	void do_read_body();
	void do_write();

private:
	tcp::socket socket_;
	ChatRoom &room_;
	ChatMessage read_msg_;
	chat_message_queue write_msgs_;

};

#endif // !CHAT_SESSION