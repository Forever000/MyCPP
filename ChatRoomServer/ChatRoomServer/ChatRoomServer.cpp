// �ļ�����GYSheng Default Template
/*
	�Ľ�Ŀ¼��
		MySQL
		Log
*/
#include"ChatServer.h"
using namespace std;

int main(int argc, char* argv[]){
	try {
		//����������
		boost::asio::io_context io_context;
		std::list<ChatServer> servers;
		if (argc < 2){
			tcp::endpoint endpoint(tcp::v4(), 8081);//�󶨶˿�
			servers.emplace_back(io_context, endpoint);//��������
			cout << "������Ѱ�Ĭ�϶˿�: " << "8081" << endl;
		}
		else {
			for (int i = 1; i < argc; ++i) {
				tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
				servers.emplace_back(io_context, endpoint);
				cout << "������Ѱ�ָ���˿�: " << std::atoi(argv[i]) << endl;
			}
		}
		io_context.run();
	}
	catch (std::exception& e){
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}