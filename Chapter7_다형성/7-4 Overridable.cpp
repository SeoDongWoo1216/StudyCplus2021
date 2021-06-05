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

	void eat()
	{
		puts("�ȳ�");
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

	void intro()
	{
		printf("%d�й� %s�Դϴ�.\n", this->stunum, this->name);
	}
};

int main()
{
	Human h("����", 10);
	Student s("���л�", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->eat();
	pH = &s;
	pH->intro();
	pH->eat();
}