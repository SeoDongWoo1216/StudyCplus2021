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
	void study()
	{
		printf("���̴� ��, �̻��� ��, �̻� �� \n");
	}
};

class Graduate : public Student
{
protected:
	char thesis[32];

public:
	Graduate(const char* name, int age, int stunum, const char* thesis) : Student(name, age, stunum)
	{
		strcpy(this->thesis, thesis);
	}

	void research()
	{
		printf("%s�� �����ϰ� ���� ����.\n", this->thesis);
	}
};

int main()
{
	Graduate hong("ȫ�浿", 45, 900102, "���ӹ��Ǻм�");
	hong.research();
}