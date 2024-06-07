#pragma once
/*
"""
抽象工厂模式

优点：

1、一个产品族中的多个对象被设计成一起工作时，它能保证客户端始终只使用同一个产品族中的对象（将一个系列的产品统一一起创建）；

缺点：

1、产品族扩展非常困难，要增加一个系列的某一产品，既要修改工厂抽象类里加代码，又修改具体的实现类里面加代码；
2、增加了系统的抽象性和理解难度；

产品族：一个品牌下面的所有产品；例如华为下面的手机，路由器，电脑称为华为的产品族；

产品等级：多个品牌下面的同种产品；例如华为和小米下面的路由器称为一个产品等级；
"""
*/
#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////抽象工厂/////////////////////////////////////////
class IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct() = NULL;
	virtual IRouterProduct *routerProduct() = NULL;
private:

};

/////////////////////////////////////////手机工厂/////////////////////////////////////////
class IPhoneProduct
{
public:
	virtual void start() = 0;
	virtual void shutDown() = 0;
	virtual void callup() = 0;
	virtual void sendSMS() = 0;
	virtual void relativeFun();

private:

};

/////////////////////////////////////////路由器工厂/////////////////////////////////////////
class IRouterProduct
{
public:
	virtual void start() = 0;
	virtual void shutDown() = 0;
	virtual void openWIFI() = 0;
	virtual void setting() = 0;
	virtual void relativeFun();

private:

};

/////////////////////////////////////////华为工厂/////////////////////////////////////////
class HuaweiFactory :public IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct();
	virtual IRouterProduct *routerProduct();

private:

};

/////////////////////////////////////////小米工厂/////////////////////////////////////////
class XiaomiFactory :public IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct();
	virtual IRouterProduct *routerProduct();

private:

};

/////////////////////////////////////////华为手机工厂/////////////////////////////////////////
class HuaweiPhone:public IPhoneProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void callup();
	virtual void sendSMS();

private:

};

/////////////////////////////////////////小米手机工厂/////////////////////////////////////////
class XiaomiPhone :public IPhoneProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void callup();
	virtual void sendSMS();

private:

};

/////////////////////////////////////////华为路由器工厂/////////////////////////////////////////
class HuaweiRouter:public IRouterProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void openWIFI();
	virtual void setting();

private:

};

/////////////////////////////////////////小米路由器工厂/////////////////////////////////////////
class XiaomiRouter :public IRouterProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void openWIFI();
	virtual void setting();

private:

};
