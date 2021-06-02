#include <iostream>
#include <stdio.h>

class StaticTest
{
public:
	int a;
	static int b;        // static ��� ���� ����
	StaticTest()
	{
		a = 10;
		// b = 20;       // Ŭ���� ���ο����� �ʱ�ȭ�� ��������.(����)
		b++;             // �����ڰ� ȣ��ɶ����� b�� 1�� ������
	}
	
	void getData() 
	{
		printf("a : %d\n", a);
		printf("b : %d\n", b);
	}
};

int StaticTest::b = 20;  // �ܺο��� �ǵ帱���� �Ҽ��� �ʿ���.
						 // static ������� �ʱ�ȭ(�ܺο��� �ʱ�ȭ���ذ���)
						 // ��ü ���� �������� �ʴ´�.
int main()
{
	StaticTest s1;
	s1.getData();        // a : 10, b : 21 ���

	StaticTest s2;
	s2.getData();        // a : 10, b : 22 ���

	return 0;
}