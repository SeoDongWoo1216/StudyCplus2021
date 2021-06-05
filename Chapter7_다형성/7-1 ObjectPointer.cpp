#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	void intro()
	{
		printf("�̸� : %s\n", this->name);
		printf("���� : %d\n", this->age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age)
	{
		this->stunum = stunum;
	}

	void intro()
	{
		printf("%d �й� %s �Դϴ�. \n", this->stunum, this->name);
	}

	void study()
	{
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int main()
{
	Human h("��ö��", 10);
	Student s("���л�", 15, 1234567);

	Human* pH;
	Student* pS;

	pH = &h;  // ���� (������ ����)
	pS = &s;  // ���� (������ ����)
	pH = &s;  // ���� (�θ��ڷ��������Ͱ� �ڽ� ��ü�� ����Ŵ -> ��ĳ����)
	// pS = &h; // ����

	pS = (Student*)&h; // �ڽ��� �θ� ����Ű�� ����(����ȯ(�ٿ�ĳ����)�� ����)
	pS->intro();
}