#include <stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro() 
	{
		printf("�̸� : %s\n", name);
		printf("���� : %d\n", age);
	}
};

int main() 
{
	Human arFriend[10] = 
	{
		{"��浿", 49},
		{"ȫ�浿", 49},
		{"�ֱ浿", 49}
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}