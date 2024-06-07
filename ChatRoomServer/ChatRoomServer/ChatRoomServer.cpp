// 文件名：GYSheng Default Template
/*
	改进目录：
		MySQL
		Log
*/
#include"ChatServer.h"
using namespace std;

int main(int argc, char* argv[]){
	try {
		//创建上下文
		boost::asio::io_context io_context;
		std::list<ChatServer> servers;
		if (argc < 2){
			tcp::endpoint endpoint(tcp::v4(), 8081);//绑定端口
			servers.emplace_back(io_context, endpoint);//创建服务
			cout << "服务端已绑定默认端口: " << "8081" << endl;
		}
		else {
			for (int i = 1; i < argc; ++i) {
				tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
				servers.emplace_back(io_context, endpoint);
				cout << "服务端已绑定指定端口: " << std::atoi(argv[i]) << endl;
			}
		}
		io_context.run();
	}
	catch (std::exception& e){
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}