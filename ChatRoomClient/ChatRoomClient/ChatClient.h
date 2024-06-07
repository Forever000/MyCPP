#pragma once
#pragma once
#ifndef CHAT_CLIENT
#define CHAT_CLIENT
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include"ChatMessage.hpp"
using namespace std;
using boost::asio::ip::tcp;

typedef std::deque<ChatMessage> chat_message_queue;

class ChatClient
{
public:
	ChatClient(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints);
	void write(const ChatMessage& msg);
	void close();

private:
	void do_connect(const tcp::resolver::results_type& endpoints);
	void do_read_header();
	void do_read_body();
	void do_write();

private:
	boost::asio::io_context& io_context_;
	tcp::socket socket_;
	ChatMessage read_msg_;
	chat_message_queue write_msgs_;
};

#endif // !CHAT_CLIENT	