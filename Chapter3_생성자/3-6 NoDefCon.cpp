#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human 
{
private:
	char name[12];
	int age;

public:
	Human()    // ����Ʈ ������
	{
		strcpy(name, "�̸�����");
		age = 0;
	}
	Human(const char* aname, int aage) 
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
	// ����Ʈ �����ڰ� ������ ����ó����
	Human momo;          // ����
	Human arFriend[3];   // ����

	Human arFriend[3] =
	{
		{ Human("��浿", 30)},
		{ Human("ȫ�浿", 31)},
		{ Human("�ֱ浿", 32)}
	};

	arFriend[2].intro();  // �迭�� 3��°�� ���(0~2)
}