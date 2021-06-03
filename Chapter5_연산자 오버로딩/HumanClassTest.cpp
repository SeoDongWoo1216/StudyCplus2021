/*
	������ �����ε� ���� ����
	1. Human class����� ��������� char *name, int age ����, ��ü �ʱ�ȭ�ϸ�� �����͸� �޾ƺ���
	   ����� ����ϴ� printHuman(); �����
	2. Human youH(myH) �� ������Ű�� ���� ������ �����
	3. Human xman
	   xman = myH;     �� ������Ű�� ���Կ����� ����Լ� �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Human
{
private:
	char* name;
	int age;

public:
	Human() 
	{
		this->name = 0;
		this->age = 0;
	}


	// ���ڰ� 2���϶� ȣ��Ǵ� ������
	Human(const char* name, const int age) // ���ڿ��̹Ƿ� *�� ����.
	{
		int len = (strlen(name) + 1);
		this->name = new char[len];   // ��������� �������̹Ƿ� ���� �Ҵ� 
		strcpy(this->name, name);     // ���ڿ��� �״�� ���������Ƿ� strcpy�� �����ؼ� �����͸� �־���

		this->age = age;

		cout << "���� 2�� ������ ȣ��" << endl;
	}


	// ��ü�� ������ �������ִ� ������
	Human(const Human&other)  
	{
		int len = (strlen(other.name) + 1);
		this->name = new char[len];
		strcpy(this->name, other.name);

		this->age = other.age;
		cout << "����޴� ������ ȣ�� " << endl;
	}


	// ���� �����ڸ� �����ϴ� ������ �Լ�
	const Human& operator =(const Human& other)
	{
		int len = (strlen(other.name) + 1);
		this->name = new char[len];
		strcpy(this->name, other.name);

		this->age = other.age;


		cout << "���Կ����� �Լ� ȣ��" << endl;
		return *this;
	}


	// �Ҹ���
	~Human()
	{
		delete[] this->name;
		cout << "�Ҹ��� ȣ��" << endl;
	}


	// ������ ���
	void printHuman()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl << endl;
	}
};


int main()
{
	Human myH("ȫ�浿", 24);
	myH.printHuman();
	
	Human youH(myH);   // ��ü�� ��������� ����
	youH.printHuman();

	Human xman;
	xman = myH;       // ��ü�� ���Կ����� ����
	xman.printHuman();

	cout << endl;
	return 0;
}