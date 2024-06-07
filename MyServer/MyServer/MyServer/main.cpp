#include<WinSock2.h>
#include<iostream>
#include<string>
#include<ctime>
#include<thread>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

void sendMsg(int cli_sock) {
	//发送消息
	string msg = "<html><head></head><body>Hello World!</body></html>";
	string httpHeader = "";
	httpHeader += "HTTP/1.1 200 OK\r\n";
	httpHeader += "Content-Type:text/html;charset-UTF-8\r\n";
	httpHeader += "Content-Length:" + sizeof(msg);
	httpHeader += "\r\n";
	httpHeader += "\r\n";//消息头与消息之间需要有一个空行
	httpHeader += msg;
	//httpHeader += "\r\n";

	const char *tem = httpHeader.c_str();
	cout << sizeof(tem) << endl;
	int ret = send(cli_sock, tem, sizeof(tem), 0);
	if (ret > 0) {
		cout << "发送成功！" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}
}

int main() {
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data)==-1) {
		cout << "初始化错误！" << endl;
		WSACleanup();
		return -1;
	}
	SOCKET m_sock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8081);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	if (::bind(m_sock, (sockaddr*)&addr, sizeof(addr))==-1) {
		cout << "bind error!" << endl;
		return -1;
	}
	if (listen(m_sock, SOMAXCONN)==-1) {
		cout << "listen error" << endl;
		return -1;
	}
	cout << "等待客户端连接..." << endl;


	sockaddr_in cli_addr;
	int len = sizeof(cli_addr);
	int cli_sock = accept(m_sock, (sockaddr*)&cli_addr, &len);//获取连接的客户端
	if (cli_sock == -1) {
		cout << "accept error";
		return -1;
	}
	cout << "客户端[" << cli_sock << "]已连接" << endl;

	//输出收到的信息
	//char buf[32] = { 0 };
	//recv(cli_sock, buf, sizeof(buf), 0);
	//cout << "收到的消息为：" << buf << endl;

	sendMsg(cli_sock);
	//thread ts(sendMsg, cli_sock);
	//ts.detach();
	//Sleep(3000);

	//WSACleanup();
	system("pause");
	return 0;
}