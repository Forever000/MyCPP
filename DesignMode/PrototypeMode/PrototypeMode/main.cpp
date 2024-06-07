#include"Prototype.h"

int main() {

	BigComponent *co = new BigComponent("BigComponent");

	ConcertPortotype1 *p1 = new ConcertPortotype1("AAAA", co);
	Prototype *p2 = (Prototype*)(p1->clone());
	p1->show();
	p2->show();

	co->setComponentName("MidComponent");
	p1->show();
	p2->show();

	system("pause");
	return 0;
}