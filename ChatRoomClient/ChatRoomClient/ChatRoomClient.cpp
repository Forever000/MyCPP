#include"ChatClient.h"

using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
	try {
		boost::asio::io_context io_context;
		tcp::resolver resolver(io_context);
		tcp::resolver::results_type endpoints;
		if (argc != 3) {
			endpoints = resolver.resolve({ "127.0.0.1", "8081" });// 连接服务器，执行 TCP 三次握手的过程。
			cout << "连接默认服务器 -" << "127.0.0.1" <<":"<< "8081" << endl;
		}
		else {
			endpoints = resolver.resolve(argv[1], argv[2]);// 连接服务器，执行 TCP 三次握手的过程。
		}

		ChatClient c(io_context, endpoints);

		std::thread t([&io_context]() { io_context.run(); });

		char line[ChatMessage::max_body_length + 1];
		while (std::cin.getline(line, ChatMessage::max_body_length + 1)) {
			ChatMessage msg;
			msg.body_length(std::strlen(line));
			std::memcpy(msg.body(), line, msg.body_length());
			msg.encode_header();
			c.write(msg);
			//cout << "客户端已发送msg:" << msg.data()<<"-"<<msg.body()<<endl;
		}

		c.close();
		t.join();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << endl;
	}
	system("pause");
	return 0;
}
