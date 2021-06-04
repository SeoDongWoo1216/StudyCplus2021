#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

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
		cout << "�̸� : " << this->name << endl;
		cout << "���� : " << this->age << endl;
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
		printf("���̴� ��, �̻��� ��, �̻�� ��\n");
	}

	void intro()  // �������̵�(�Լ� ������)
		          // �ڽ� Ŭ�������� intro() �Լ�
	{
		printf("%d�й� %s�Դϴ�.\n", this->stunum, this->name);
	}
};

int main()
{
	Human hong("ȫ�浿", 30);
	hong.intro();
	printf("\n");

	Student kim("��浿", 20, 123456);
	kim.intro();
	printf("\n");

	// �ڽ� Ŭ�����ε� �̸�, ���̸� ����ϴ� intro()�� ����ϰ�ʹ�
	// => �ڽ� Ŭ���� ��ü�ε� �θ� Ŭ������ intro�� �ʿ��ϴ�.
	kim.Human::intro();   // => �Լ��� �Ҽ� Ŭ������ ���ָ� ����
	printf("\n");

}