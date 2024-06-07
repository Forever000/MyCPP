#include"AbstractFactoryMode.h"

/////////////////////////////////////实现每个产品族//////////////////////////////////////////////////
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


/////////////////////////////////////Huawei手机//////////////////////////////////////////////////
void HuaweiPhone::start() {
	cout << "Huawei手机开机..." << endl;
}
void HuaweiPhone::shutDown() {
	cout << "Huawei手机关机..." << endl;
}
void HuaweiPhone::callup() {
	cout << "正在使用Huawei手机发信息..." << endl;
}
void HuaweiPhone::sendSMS() {
	cout << "正在使用Huawei手机打电话..." << endl;
}

/////////////////////////////////////Huawei路由器//////////////////////////////////////////////////
void HuaweiRouter::start() {
	cout << "Huawei路由器开机..." << endl;
}
void HuaweiRouter::shutDown() {
	cout << "Huawei路由器关机..." << endl;
}
void HuaweiRouter::openWIFI() {
	cout << "Huawei路由器打开WIFI..." << endl;
}
void HuaweiRouter::setting() {
	cout << "Huawei路由器打开设置..." << endl;
}

/////////////////////////////////////Xiaomi手机//////////////////////////////////////////////////
void XiaomiPhone::start() {
	cout << "XiaomiPhone手机开机..." << endl;
}
void XiaomiPhone::shutDown() {
	cout << "XiaomiPhone手机关机..." << endl;
}
void XiaomiPhone::callup() {
	cout << "正在使用XiaomiPhone手机发信息..." << endl;
}
void XiaomiPhone::sendSMS() {
	cout << "正在使用XiaomiPhone手机打电话..." << endl;
}

/////////////////////////////////////Xiaomi路由器//////////////////////////////////////////////////
void XiaomiRouter::start() {
	cout << "Xiaomi路由器开机..." << endl;
}
void XiaomiRouter::shutDown() {
	cout << "Xiaomi路由器关机..." << endl;
}
void XiaomiRouter::openWIFI() {
	cout << "Xiaomi路由器打开WIFI..." << endl;
}
void XiaomiRouter::setting() {
	cout << "Xiaomi路由器打开设置..." << endl;
}

