#include <stdio.h>

int main() 
{
	enum origin {EAST, WEST, SOUTH, NORTH};
	// enum origin mark = WEST;

	origin mark = WEST;
	printf("%d ����\n", mark);

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};

	// struct SHuman kim = { "ȫ�浿", 30, 200.4 };
	SHuman kim = { "ȫ�浿", 30, 200.4 };
	
	printf("�̸� = %s, ���� = %d\n", kim.name, kim.age);
}