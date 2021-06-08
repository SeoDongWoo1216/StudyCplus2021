#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

class Human
{
private:
	char* name;
	int age;

public:
	Human()                                // ����Ʈ ������
	{
		this->name = new char[1];
		name[0] = NULL;
		this->age = 0;
	}

	Human(const char* name, int age)       // 2���� ���ڸ� ���� ������
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}

	Human(const Human& other)              // (�������·� �Ű������� ��) ��������� �̸鼭 ��ȯ������(���� 1��)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->age = other.age;
	}

	Human& operator =(const Human& other)  // ������ �����ε�
	{
		if (this != &other)
		{
			delete[] name;
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
			this->age = other.age;
		}

		return *this;
	}

	~Human()                               // �Ҹ���
	{
		delete[] name;
	}

	void intro()                           // ��� �Լ�
	{
		printf("�̸� : %s\n", this->name);
		printf("���� : %d\n", this->age);
	}
};


int main()
{
	Human hong("ȫ�浿", 10);
	Human kim("��浿", 20);

	hong.intro();
	kim.intro();
	printf("\n");

	swap(hong, kim);

	hong.intro();
	kim.intro();
	printf("\n");

}