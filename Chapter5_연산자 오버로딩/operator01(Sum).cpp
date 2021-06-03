#include <iostream>
using namespace std;
class MyTest
{
private:
	int x;
	int y;

public:
	// ��� ������ ���� 2���� ��ü�� ���ϴ� ������ϴ� ��� �Լ�(Sum) �����, ����, �Է¹���
	MyTest()  // ���ھ��� ��ü�� ���������������� ����Ʈ ������
	{

	}

	MyTest(int x, int y)  // 2���� ���ڸ� �޾������� ������
	{
		this->x = x;
		this->y = y;
	}

	void printData()
	{
		cout << "x : " << this->x << endl;
		cout << "y : " << this->y << endl;
	}

	// ���� const�� ���ϰ��� �ٲ��ȵ�
	// �Ű����� const�� �Ű������� �ٲ��ȵ�
	// ���� const�� this->x, this->y�� ���� �ٲ�� �ȵ�
	const MyTest Sum(const MyTest&other) const
	{
		MyTest t;
		t.x = this->x + other.x;
		t.y = this->y + other.y;

		return t;
	}
	
};

int main() 
{
	MyTest obj1(10, 20);
	MyTest obj2(30, 50);
	MyTest obj3;

	obj3 = obj1.Sum(obj2);
	obj3.printData();

	return 0;
}