#pragma once
#ifndef CHAT_SERVER
#define CHAT_SERVER

#include"ChatSession.h"
using namespace std;

class ChatServer
{
public:
	ChatServer(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);

private:
	void do_accept();

private:
	tcp::acceptor acceptor_;
	ChatRoom room_;

};
#endif // !CHAT_SERVER