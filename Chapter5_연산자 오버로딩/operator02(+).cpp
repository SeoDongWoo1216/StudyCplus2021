#include <iostream>
using namespace std;

class MyTest
{
private:
	int x;
	int y;
public:
	MyTest() 
	{
		cout << "����Ʈ ������ ȣ��" << endl;
	}
	MyTest(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << "�μ� 2�� ������ ȣ��" << endl;
	}

	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y)
	{
		cout << "��������� ȣ��" << endl;
	}

	const MyTest& operator +(const MyTest& other) const
	{
		MyTest t;       // temp ��ü�� �����ߴµ� ����Ʈ ��ü�� ȣ���
		t.x = this->x + other.x;
		t.y = this->y + other.y;
		return t;       // ��ü�� ��ȯ�Ҷ� �ӽ� ��ü�� ��������� t�� ����� ���� ������
		                // => ��������ڰ� ȣ���.
		                // �����ϱ����� �ӽ� ��ü�� ���� ��������� ȣ��
		                // ���α׷����� �ʿ���� => ���ɿ� ��������
		                // �׷��� ����� �������·� �ٲٴ°���
		                // �������·� �ٲٸ� ��������ڰ� ȣ���������.

		// # �Ű�����, ����϶� �Ű������� ���� ���۷����� ���.#
		// ���Ÿ���� �׻� �������·� ��������
		// �ӽð�ü�� ����������ʾƼ� ��������ڰ� ȣ���̾ȵ� => ���ɿ� ������ ��
	}

	void printData()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
	}
};


int main()
{
	MyTest c1(10, 20);
	MyTest c2(20, 50);
	MyTest c3;

	c3 = c1 + c2;
	c3.printData();

	return 0;
}