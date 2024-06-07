#pragma once
#include"Component.h"

class Prototype
{
public:
	virtual Prototype *clone() = 0;

	void setName(string name) {
		m_typename = name;
	}

	void show() {
		cout << "typename = " << m_typename<<" ";
		component->show();
	}
protected:
	Component *component;
	string m_typename;
};


class ConcertPortotype1 :public Prototype {
public:
	ConcertPortotype1(string name,Component *component) {
		m_typename = name;
		this->component = component;
	}

	virtual Prototype *clone() {
		ConcertPortotype1 *p = new ConcertPortotype1(m_typename, component->clone());
		return p;
	}

	
private:
	
};

class ConcertPortotype2 :public Prototype {
public:
	ConcertPortotype2(string name, Component *component) {
		m_typename = name;
		this->component = component;
	}

	virtual Prototype *clone() {
		ConcertPortotype2 *p = new ConcertPortotype2(m_typename, component->clone());
		return p;
	}

private:
};