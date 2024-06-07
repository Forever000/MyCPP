#include"Agent.h"


void MySystem::run() {
	cout << "程序启动..." << endl;
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
		cout << "用户名和密码有误，验证通过..." << endl;
		this->pSystem->run();
	}
	else {
		cout << "用户名或密码有误，权限不足..." << endl;
	}
}
MySystemProxy::~MySystemProxy() {
	if (pSystem != NULL) {
		delete pSystem;
	}
}