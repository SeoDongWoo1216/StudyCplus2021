#include <stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();
};

void SHuman::intro() 
{
	printf("�̸� = %s\n", name);
	printf("���� = %d\n", age);
}

int main() 
{
	SHuman kim = { "ȫ�浿" , 30 };
	kim.intro();
}