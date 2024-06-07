#include"AbstractFactoryMode.h"

int main() {
	IProductFactory *factory = NULL;

	factory = new XiaomiFactory();
	IPhoneProduct *phoneProduct = factory->phoneProduct();
	//phoneProduct->start();
	//phoneProduct->callup();
	//phoneProduct->sendSMS();
	//phoneProduct->shutDown();
	phoneProduct->relativeFun();

	IRouterProduct *routerProduct = factory->routerProduct();
	//routerProduct->start();
	//routerProduct->openWIFI();
	//routerProduct->setting();
	//routerProduct->shutDown();
	routerProduct->relativeFun();

	
	factory = new HuaweiFactory();
	phoneProduct = factory->phoneProduct();
	//phoneProduct->start();
	//phoneProduct->callup();
	//phoneProduct->sendSMS();
	//phoneProduct->shutDown();
	phoneProduct->relativeFun();

	routerProduct = factory->routerProduct();
	//routerProduct->start();
	//routerProduct->openWIFI();
	//routerProduct->setting();
	//routerProduct->shutDown();
	routerProduct->relativeFun();

	system("pause");
	return 0;
}