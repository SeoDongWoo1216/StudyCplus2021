#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// �θ� Ŭ���� ����
class Human
{
private:
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


// �ڽ� Ŭ���� ����
class Student : public Human  // : �� ���� ��ӽ����ִ°���
{
private:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age)  // �ݷ� �ʱ�ȭ
	{
		this->stunum = stunum;
	}

	void study()
	{
		cout << "�й� : " << this->stunum << endl;
		cout << "22�� 4, 23�� 6, 24 8" << endl;
	}
};

int main()
{
	Human kim("��浿", 29);
	kim.intro();

	Student hong("ȫ�浿", 15, 123456);  // ������ Ŭ������ �����ϸ鼭 123456�� ó���ϴ� Ŭ������ ���� ���� -> ���뼺, ���
	hong.intro();   // Human���κ��� ��ӹ޾Ƽ� intro�� ����� �� ����.
	hong.study();
}

