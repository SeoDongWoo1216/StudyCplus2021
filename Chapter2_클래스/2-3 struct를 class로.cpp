#include <stdio.h>

class Human   
{

public:             // private�� ���� ����
	char name[20];
	int age;

	void intro()
	{
		printf("�̸� : %s\n", name);
		printf("���� : %d\n", age);
	}
};

int main()
{
	Human kim = { "��浿", 30 };

	kim.intro(); 
}