#include"ChatSession.h"

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room)
	: socket_(std::move(socket))
	,room_(room) 
{}

//将新连接的客户端会话加入聊天室
void ChatSession::start() {
	room_.join(shared_from_this());
	do_read_header();
}

//将最近的所有消息收集完毕之后转发
void ChatSession::deliver(const ChatMessage& msg) {
	cout << "消息转发..." << endl;
	bool write_in_progress = !write_msgs_.empty();
	write_msgs_.push_back(msg);
	if (!write_in_progress) {
		do_write();
	}
}

void ChatSession::do_read_header() {
	cout << "消息读取中..." << endl;
	//异步读取客户端发送的消息至data数组
	auto self(shared_from_this());
	boost::asio::async_read(socket_,
		boost::asio::buffer(read_msg_.data(), ChatMessage::header_length),
		[this, self](boost::system::error_code ec, std::size_t lens)
	{
		if (!ec && read_msg_.decode_header()) {
			do_read_body();
		}
		else {
			room_.leave(shared_from_this());
		}
	});
}

void ChatSession::do_read_body() {
	auto self(shared_from_this());
	boost::asio::async_read(socket_,
		boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
		[this, self](boost::system::error_code ec, std::size_t lens)
	{
		if (!ec) {
			room_.deliver(read_msg_);
			do_read_header();//继续等待客户端的下一次数据
			cout << "继续等待客户端的下一次数据..." << endl;
		}
		else {
			room_.leave(shared_from_this());
		}
	});
}

void ChatSession::do_write() {
	//转发消息队列中的所有消息
	auto self(shared_from_this());
	boost::asio::async_write(socket_,
		boost::asio::buffer(write_msgs_.front().data(),
			write_msgs_.front().length()),
		[this, self](boost::system::error_code ec, std::size_t lens)
	{
		if (!ec) {
			write_msgs_.pop_front();
			if (!write_msgs_.empty()) {
				do_write();
			}
		}
		else {
			room_.leave(shared_from_this());
		}
	});
}