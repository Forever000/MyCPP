#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Company.h"
class Programmer {
public:
	Programmer(Company *company):m_company(company){}
	virtual void codding(char *buff) = 0;
protected:
	Company *m_company;
};

class ProgrammerCpp:public Programmer {
public:
	ProgrammerCpp(Company *company) :Programmer(company) {}
	virtual void codding(char *buff) {
		strcpy(buff, "cout<<\"Hello World!<<endl;\"");
		m_company->working(buff);
	}
};

class ProgrammerJava :public Programmer {
public:
	ProgrammerJava(Company *company) :Programmer(company) {}
	virtual void codding(char *buff) {
		strcpy(buff, "System.Out.Println(\"Hello World!);\"");
		m_company->working(buff);
	}
};

class ProgrammerPython :public Programmer {
public:
	ProgrammerPython(Company *company) :Programmer(company) {}
	virtual void codding(char *buff) {
		strcpy(buff, "print(\"Hello World!);\"");
		m_company->working(buff);
	}
};
