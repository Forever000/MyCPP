#define _WINSOCK_DEPRECATED_NO_WARNINGS
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
	int ret = send(cli_sock, tem, sizeof(tem), 0);
	if (ret > 0) {
		cout << "发送成功！" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}
}
int main() {
	//初始化
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) == -1) {
		cout << "初始化错误！" << endl;
		WSACleanup();
		return -1;
	}
	//创建套接字
	SOCKET m_sock = socket(AF_INET, SOCK_STREAM, 0);
	//指定通信的ip和端口
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8081);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//向服务器发起连接请求
	if (connect(m_sock, (sockaddr*)&addr, sizeof(addr)) == -1) {
		cout << "bind error!" << endl;
		return -1;
	}
	
	cout << "服务器连接成功..." << endl;

	//接收数据
	char buf[32] = { 0 };
	recv(m_sock, buf, sizeof(buf), 0);
	if (buf) {
		cout << "收到的消息为：" << buf << endl;
	}
	
	//发送数据
	sendMsg(m_sock);

	//关闭socket连接，释放资源
	WSACleanup();

	system("pause");
	return 0;
}