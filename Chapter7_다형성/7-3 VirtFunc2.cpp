// intro�� virtual�� �߰��غ���.

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

	virtual void intro()
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

	virtual void intro()
	{
		printf("%d�й� %s�Դϴ�.", this->stunum, name);
	}

	void study()
	{
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

void IntroSomeBody(Human* pH)
{
	pH->intro();
}

int main()
{
	Human h("����", 10);
	Student s("���л�", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();
}