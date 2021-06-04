/*
	1. Human �θ�Ŭ���� ����
	printname�� �����ϸ�

	2. �л� Ŭ��������� �޸��� ��ӹޱ�
	�л�Ŭ������ ����(char *major) ���� �Ŀ� printmajor ����Լ� ����
	printmajor ����ϸ� �ڱ��̸�, IoT ����ϵ���

*/
#include <iostream>
using namespace std;

class Human
{
private:
	char* name;

public:
	Human()
	{
		this->name = 0;
	}
	
	Human(const char *name)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	~Human()
	{
		delete[] this->name;
		cout << "�Ҹ��� ȣ��" << endl;
	}

	void printname()
	{
		cout << "My name is " << this->name << endl;
	}
};


class Student : public Human   // Human�� ��ӹ޴� Student Ŭ���� ����
{
private:
	char* major;

public:
	Student()
	{
		this->major = 0;
	}

	Student(const char *name, const char *major) : Human(name)
	{
		int len = strlen(major) + 1;
		this->major = new char[len];
		strcpy_s(this->major, len, major);
	}

	void printMajor()
	{
		printname();
		cout << "My major is " << this->major << endl;
	}
};

int main()
{
	Human my("ȫ�浿");
	my.printname();
	cout << endl;

	Student s("��浿", "IoT");
	s.printMajor();   // My name is ȫ�浿, My major is IoT
	cout << endl;

	return 0;
}