// �����̸� : Constructor.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


class Human
{
private:
	char name[12];
	int age;

public:
	// ������
	Human(const char* aname, int aage) // Ŭ������ �̸�������, ���ϰ��̾����� �������̴�.
	{
		strcpy(name, aname);
		age = aage;
	}

	void intro() 
	{
		printf("�̸� : %s\n", name);
		printf("���� : %d\n", age);
	}
};

int main() 
{
	Human hong("ȫ�浿", 30);
	hong.intro();
}