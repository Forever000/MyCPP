#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class AbstractCommonInterface
{
public:
	virtual void run() = 0;

private:

};

class MySystem:public AbstractCommonInterface
{
public:
	virtual void run();

private:

};

class MySystemProxy:public AbstractCommonInterface
{
public:
	MySystemProxy(string userName, string password);
	bool judgeUserPass();
	virtual void run();
	~MySystemProxy();

private:
	string m_userName;
	string m_password;
	MySystem *pSystem = NULL;

};
