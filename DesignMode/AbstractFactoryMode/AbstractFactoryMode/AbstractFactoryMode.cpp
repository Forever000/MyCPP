#include"AbstractFactoryMode.h"

/////////////////////////////////////ʵ��ÿ����Ʒ��//////////////////////////////////////////////////
IPhoneProduct *HuaweiFactory::phoneProduct() {
	return new HuaweiPhone();
}

IRouterProduct *HuaweiFactory::routerProduct() {
	return new HuaweiRouter();
}

IPhoneProduct *XiaomiFactory::phoneProduct() {
	return new XiaomiPhone();
}
IRouterProduct *XiaomiFactory::routerProduct() {
	return new XiaomiRouter();
}

void IPhoneProduct::relativeFun() {
	this->start();
	this->callup();
	this->sendSMS();
	this->shutDown();
}

void IRouterProduct::relativeFun() {
	this->start();
	this->openWIFI();
	this->setting();
	this->shutDown();
}


/////////////////////////////////////Huawei�ֻ�//////////////////////////////////////////////////
void HuaweiPhone::start() {
	cout << "Huawei�ֻ�����..." << endl;
}
void HuaweiPhone::shutDown() {
	cout << "Huawei�ֻ��ػ�..." << endl;
}
void HuaweiPhone::callup() {
	cout << "����ʹ��Huawei�ֻ�����Ϣ..." << endl;
}
void HuaweiPhone::sendSMS() {
	cout << "����ʹ��Huawei�ֻ���绰..." << endl;
}

/////////////////////////////////////Huawei·����//////////////////////////////////////////////////
void HuaweiRouter::start() {
	cout << "Huawei·��������..." << endl;
}
void HuaweiRouter::shutDown() {
	cout << "Huawei·�����ػ�..." << endl;
}
void HuaweiRouter::openWIFI() {
	cout << "Huawei·������WIFI..." << endl;
}
void HuaweiRouter::setting() {
	cout << "Huawei·����������..." << endl;
}

/////////////////////////////////////Xiaomi�ֻ�//////////////////////////////////////////////////
void XiaomiPhone::start() {
	cout << "XiaomiPhone�ֻ�����..." << endl;
}
void XiaomiPhone::shutDown() {
	cout << "XiaomiPhone�ֻ��ػ�..." << endl;
}
void XiaomiPhone::callup() {
	cout << "����ʹ��XiaomiPhone�ֻ�����Ϣ..." << endl;
}
void XiaomiPhone::sendSMS() {
	cout << "����ʹ��XiaomiPhone�ֻ���绰..." << endl;
}

/////////////////////////////////////Xiaomi·����//////////////////////////////////////////////////
void XiaomiRouter::start() {
	cout << "Xiaomi·��������..." << endl;
}
void XiaomiRouter::shutDown() {
	cout << "Xiaomi·�����ػ�..." << endl;
}
void XiaomiRouter::openWIFI() {
	cout << "Xiaomi·������WIFI..." << endl;
}
void XiaomiRouter::setting() {
	cout << "Xiaomi·����������..." << endl;
}

