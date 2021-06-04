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
		printf("�̸� : %s\n", name);
		printf("���� : %d\n", age);
	}

};

class Student : public Human // public ���� ����Ʈ���� private�� ��ӾȵǼ� ���پȵ�
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
		cout << "���̴� ��, �̻��� ��, �̻� ��" << endl;
	}

	void report()
	{
		printf("�̸� : %s\n", this->name);
		printf("�й� : %d, ���� ����\n", this->stunum);
	}

};

int main() 
{
	Student kim("��浿", 20, 123456);
	kim.intro();
	kim.study();
	kim.report();
}

// ����Ҷ� public�� ���� �⺻������ private
// ��� ������ ����Ʈ�� private
// ����ü�� ����Ʈ�� public