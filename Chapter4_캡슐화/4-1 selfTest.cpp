/*
	�����׽�Ʈ)
	Human Ŭ������ ��� ������ ����� �׼��� �Լ��� �ۼ�
	�̸��� 12�̸��� ��츸 �޾Ƶ��̰� �� �̻��� �� ���ڿ��� �����Ѵ�.
	���̴� 0~120 ������ �����ϸ� ���� ���� ���̴� 0�� �����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char *name, int age)
	{
		SetName(name);
		Setage(age);
	}

	
	char* GetName(){ return name; }
	void SetName(const char* name)  // �ܺο��� ���� ���޹��� ��� �Լ�
	{
		if (strlen(name) < 12) 
		{
			strcpy(this->name, name);
		}
		else
		{
			strcpy(this->name, "");
		}
	}

	int Getage() { return age; }
	void Setage(int age)
	{
		if (age <= 120 && age >= 0)
		{
			this->age = age;
		}
		else
		{
			this->age = 0;
		}
	}

	void printHuman()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl << endl;
	}
};


int main()
{
	/*Human hong;
	hong.SetName("ȫ�浿ȫ�浿ȫ�浿ȫ�浿");
	hong.Setage(138);
	hong.printHuman();

	hong.SetName("�浿��");
	hong.Setage(100);
	hong.printHuman();*/

	// �Է¿���޾Ƽ� �غ���
	char tempName[100];
	int tempage;

	cout << "�̸� �Է� : ";
	cin >> tempName;

	cout << "���� �Է� : ";
	cin >> tempage;

	Human hong(tempName, tempage);
	hong.printHuman();


}