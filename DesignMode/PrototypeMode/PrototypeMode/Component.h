#pragma once
#include<string>
#include<iostream>
using namespace std;
class Component
{
public:
	virtual Component *clone() = 0;

	void setComponentName(string name) {
		m_ComponentName = name;
	}

	void show() {
		cout << "ComponentName = " << m_ComponentName << endl;
	}
protected:
	string m_ComponentName;
};


class BigComponent :public Component {
public:
	BigComponent(string name) {
		m_ComponentName = name;
	}

	virtual BigComponent *clone() {
		BigComponent *p = new BigComponent(this->m_ComponentName);
		*p = *this;
		return p;
	}
};