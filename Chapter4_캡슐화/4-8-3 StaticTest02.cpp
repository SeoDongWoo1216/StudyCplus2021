#include <iostream>

class StaticTest
{
	static int a;
	int b;                  // static ��� ���� ����
public:
	StaticTest();
	static void setData(int);  // static ��� �Լ��� static ��������� ����Ѵ�.
	void getData();
};


int StaticTest::a = 10;     // static ��� ���� �ʱ�ȭ


StaticTest::StaticTest()
{
	this->b = 20;
}

void StaticTest::getData()
{
	printf("a : %d, b : %d\n", a, b);
}

void StaticTest::setData(int aa) 
{
	// this->a = aa;  // this->a�� ������������� ����� �� �ִ�.

	// a��� static ��������� ��ü���� �ƴ϶� this�� ����Ҽ�����
	// Ŭ��������
	a = aa;
}

int main()
{
	StaticTest s1;
	s1.getData();

	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	// ��ü�� ��������ʰ� Ŭ������ �Ҽӵ� setData(����Լ�) ȣ��
	StaticTest::setData(40);  // Ŭ���� �Ҽ����� ȣ���� ������.
	s1.getData();             // ����ϴϱ� a = 40 ���(���� �ٲ����)
	s2.getData();

	return 0;
}