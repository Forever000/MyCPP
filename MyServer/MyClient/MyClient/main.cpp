#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<ctime>
#include<thread>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

void sendMsg(int cli_sock) {
	//������Ϣ
	string msg = "<html><head></head><body>Hello World!</body></html>";
	string httpHeader = "";
	httpHeader += "HTTP/1.1 200 OK\r\n";
	httpHeader += "Content-Type:text/html;charset-UTF-8\r\n";
	httpHeader += "Content-Length:" + sizeof(msg);
	httpHeader += "\r\n";
	httpHeader += "\r\n";//��Ϣͷ����Ϣ֮����Ҫ��һ������
	httpHeader += msg;
	//httpHeader += "\r\n";

	const char *tem = httpHeader.c_str();
	int ret = send(cli_sock, tem, sizeof(tem), 0);
	if (ret > 0) {
		cout << "���ͳɹ���" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}
}
int main() {
	//��ʼ��
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) == -1) {
		cout << "��ʼ������" << endl;
		WSACleanup();
		return -1;
	}
	//�����׽���
	SOCKET m_sock = socket(AF_INET, SOCK_STREAM, 0);
	//ָ��ͨ�ŵ�ip�Ͷ˿�
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8081);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//�������������������
	if (connect(m_sock, (sockaddr*)&addr, sizeof(addr)) == -1) {
		cout << "bind error!" << endl;
		return -1;
	}
	
	cout << "���������ӳɹ�..." << endl;

	//��������
	char buf[32] = { 0 };
	recv(m_sock, buf, sizeof(buf), 0);
	if (buf) {
		cout << "�յ�����ϢΪ��" << buf << endl;
	}
	
	//��������
	sendMsg(m_sock);

	//�ر�socket���ӣ��ͷ���Դ
	WSACleanup();

	system("pause");
	return 0;
}