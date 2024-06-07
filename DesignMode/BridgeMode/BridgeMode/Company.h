#pragma once
#include<string>
#include<iostream>
class Company {
public:
	virtual void working(char *buff)=0;
};
class BigCompany:public Company {
public:
	virtual void working(char *buff) {
		int len = strlen(buff);
		double money = 1.0*len;
		std::cout << "Get " << money << std::endl;
	}
};

class MidCompany :public Company {
public:
	virtual void working(char *buff) {
		int len = strlen(buff);
		double money = 0.5*len;
		std::cout << "Get " << money << std::endl;
	}
};

class SmallCompany :public Company {
public:
	virtual void working(char *buff) {
		int len = strlen(buff);
		double money = 0.3*len;
		std::cout << "Get " << money << std::endl;
	}
};

