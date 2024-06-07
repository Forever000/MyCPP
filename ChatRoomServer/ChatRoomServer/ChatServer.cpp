#include"ChatServer.h"
ChatServer::ChatServer(boost::asio::io_context& io_context,
	const tcp::endpoint& endpoint)
	: acceptor_(io_context, endpoint)
{
	do_accept();
}

void ChatServer::do_accept() {
	acceptor_.async_accept(
		[this](boost::system::error_code ec, tcp::socket socket)
	{
		if (!ec) {
			//每个客户端作为一个会话对象
			std::make_shared<ChatSession>(std::move(socket), room_)->start();
		}

		do_accept();//继续等待下一个客户端连接
		cout << "继续等待下一个客户端连接" << endl;
	});
}