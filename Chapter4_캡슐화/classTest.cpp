/*
	ȸ���̸�, ��ȭ��ȣ, �ּ�, count�� ��������� ���� class�� ����
	count�� ���� ��� ������ �ۼ�=> ��ü�� �����Ҷ����� �ڵ����� 1����
	getdata�� ȣ���ϸ� �����ߴ� �̸�, ��ȣ, �ּ�, count ���
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


class CMember
{
private:
	char name[20];
	char phone[15];
	char addr[50];
	static int count;

public:
	// ���ڿ��� �������� �����̶� const�� �ٿ������.
	CMember(const char* aname, const char* aphone, const char* aaddr) 
	{ 
		strcpy(this->name, aname);
		strcpy(this->phone, aphone);
		strcpy(this->addr, aaddr);
		count++;
	}
	

	~CMember()
	{ 
		
		cout << "�Ҹ��� ȣ��, �����ִ� ȸ�� �� : " << --count << endl;
	}


	static void InitCount()
	{
		count = 0;
	}


	static void OutCount()
	{
		cout << "���� ȸ�� �� : " << count << endl;
	}


	void getData() 
	{
		cout << "##### " << count << "��° ȸ�� #####" << endl;
		cout << "�̸� : " << this->name << endl;
		cout << "��ȣ : " << this->phone << endl;
		cout << "�ּ� : " << this->addr << endl;
		cout << endl;
	}

};

//static int CMember::count = 0;
int CMember::count;

int main()
{
	CMember::InitCount();

	CMember c1("ȫ�浿", "010-1234-5678", "���ѹα� ���");
	c1.getData();

	CMember c2("��浿", "010-1111-2222", "�ѹݵ� �ƹ�����");
	c2.getData();

	return 0;
}

