/*
	�Ž�ģʽ��
		�ŵ㣺ҵ����չ���㣬�ɸ���ʵ��ҵ����Ҫͨ���̳з�ʽ������չ
		ȱ�㣺��Ҫ��д��������ɼ���ʽ������
		���ó������ر��ʺϳ���������ʵ�����Ͷ����ķ����ܴ����Ϊ�������ⳡ���ķ�������У�
		����һ�����漰�����еĲ�ͬ����ʵ�壬��ˣ��ڷ�����Ҫʱ����ҵ�񳡾��̳���д�Զ���ʵ�弴�ɡ�
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
