#include"Agent.h"


void MySystem::run() {
	cout << "��������..." << endl;
}

MySystemProxy::MySystemProxy(string userName, string password) {
	this->m_userName = userName;
	this->m_password = password;
	pSystem = new MySystem;
}
bool MySystemProxy::judgeUserPass() {
	if (this->m_userName == "admin"&&this->m_password == "admin") {
		return true;
	}
	return false;
}
void MySystemProxy::run() {
	if (judgeUserPass()) {
		cout << "�û���������������֤ͨ��..." << endl;
		this->pSystem->run();
	}
	else {
		cout << "�û�������������Ȩ�޲���..." << endl;
	}
}
MySystemProxy::~MySystemProxy() {
	if (pSystem != NULL) {
		delete pSystem;
	}
}