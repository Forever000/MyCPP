#include"ChatSession.h"

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room)
	: socket_(std::move(socket))
	,room_(room) 
{}

//�������ӵĿͻ��˻Ự����������
void ChatSession::start() {
	room_.join(shared_from_this());
	do_read_header();
}

//�������������Ϣ�ռ����֮��ת��
void ChatSession::deliver(const ChatMessage& msg) {
	cout << "��Ϣת��..." << endl;
	bool write_in_progress = !write_msgs_.empty();
	write_msgs_.push_back(msg);
	if (!write_in_progress) {
		do_write();
	}
}

void ChatSession::do_read_header() {
	cout << "��Ϣ��ȡ��..." << endl;
	//�첽��ȡ�ͻ��˷��͵���Ϣ��data����
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
			do_read_header();//�����ȴ��ͻ��˵���һ������
			cout << "�����ȴ��ͻ��˵���һ������..." << endl;
		}
		else {
			room_.leave(shared_from_this());
		}
	});
}

void ChatSession::do_write() {
	//ת����Ϣ�����е�������Ϣ
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