#pragma once
/*
"""
���󹤳�ģʽ

�ŵ㣺

1��һ����Ʒ���еĶ��������Ƴ�һ����ʱ�����ܱ�֤�ͻ���ʼ��ֻʹ��ͬһ����Ʒ���еĶ��󣨽�һ��ϵ�еĲ�Ʒͳһһ�𴴽�����

ȱ�㣺

1����Ʒ����չ�ǳ����ѣ�Ҫ����һ��ϵ�е�ĳһ��Ʒ����Ҫ�޸Ĺ�����������Ӵ��룬���޸ľ����ʵ��������Ӵ��룻
2��������ϵͳ�ĳ����Ժ�����Ѷȣ�

��Ʒ�壺һ��Ʒ����������в�Ʒ�����绪Ϊ������ֻ���·���������Գ�Ϊ��Ϊ�Ĳ�Ʒ�壻

��Ʒ�ȼ������Ʒ�������ͬ�ֲ�Ʒ�����绪Ϊ��С�������·������Ϊһ����Ʒ�ȼ���
"""
*/
#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////���󹤳�/////////////////////////////////////////
class IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct() = NULL;
	virtual IRouterProduct *routerProduct() = NULL;
private:

};

/////////////////////////////////////////�ֻ�����/////////////////////////////////////////
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

/////////////////////////////////////////·��������/////////////////////////////////////////
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

/////////////////////////////////////////��Ϊ����/////////////////////////////////////////
class HuaweiFactory :public IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct();
	virtual IRouterProduct *routerProduct();

private:

};

/////////////////////////////////////////С�׹���/////////////////////////////////////////
class XiaomiFactory :public IProductFactory
{
public:
	virtual IPhoneProduct *phoneProduct();
	virtual IRouterProduct *routerProduct();

private:

};

/////////////////////////////////////////��Ϊ�ֻ�����/////////////////////////////////////////
class HuaweiPhone:public IPhoneProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void callup();
	virtual void sendSMS();

private:

};

/////////////////////////////////////////С���ֻ�����/////////////////////////////////////////
class XiaomiPhone :public IPhoneProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void callup();
	virtual void sendSMS();

private:

};

/////////////////////////////////////////��Ϊ·��������/////////////////////////////////////////
class HuaweiRouter:public IRouterProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void openWIFI();
	virtual void setting();

private:

};

/////////////////////////////////////////С��·��������/////////////////////////////////////////
class XiaomiRouter :public IRouterProduct
{
public:
	virtual void start();
	virtual void shutDown();
	virtual void openWIFI();
	virtual void setting();

private:

};
