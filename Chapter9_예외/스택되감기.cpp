#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() ����" << endl;
	// throw 0;
	cout << "TestFunc1() ����" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2() ����" << endl;
	// TestFunc1();
	throw 0;
	cout << "TestFunc2() ����" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3() ����" << endl;
	TestFunc2();
	cout << "TestFunc3() ����" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}
	catch (...)   // ... �� ��� Ÿ���� �� �޴´ٴ� �ǹ�
	{
		cout << "���� �߻�" << endl;
	}
	TestFunc1();
	return 0;
}

// ����Ǯ�� : �Լ��� ��ȯ���� �ʰ� ������ Ǯ�����.