#include"Agent.h"

int main()
{
	AbstractCommonInterface *agent =new MySystemProxy("adamin", "admin");
	agent->run();
	system("pause");
	return 0;
}