/*
	桥接模式：
		优点：业务扩展方便，可根据实际业务需要通过继承方式轻松扩展
		缺点：需要重写类的数量成几何式的增长
		适用场景：特别适合场景复杂且实体类型多样的仿真框架搭建。因为对于特殊场景的仿真过程中，
		并不一定会涉及到所有的不同类型实体，因此，在仿真需要时根据业务场景继承重写自定义实体即可。
*/


#include"Programmer.h"
int main() {
	BigCompany bigcompany;
	MidCompany midcompany;
	SmallCompany smallcompany;


	ProgrammerCpp cppprogrammer(&bigcompany);
	ProgrammerJava javaprogrammer(&midcompany);
	ProgrammerPython pythonprogrammer(&smallcompany);

	char buff[1024];
	cppprogrammer.codding(buff);
	javaprogrammer.codding(buff);
	pythonprogrammer.codding(buff);


	system("pause");
	return 0;
}
