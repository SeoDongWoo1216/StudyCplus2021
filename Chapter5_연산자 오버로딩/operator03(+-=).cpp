/*
	��ü�� ������ �ϱ����� �����ڸ� ���� ������.
*/

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

	const MyTest& operator +(const MyTest& other) const
	{
		MyTest t;       
		t.x = this->x + other.x;
		t.y = this->y + other.y;
		return t;      
	}

	const MyTest& operator -(const MyTest& other) const
	{
		MyTest t;
		t.x = this->x - other.x;
		t.y = this->y - other.y;
		return t;
	}

	const MyTest& operator =(const MyTest& other) /*const*/
	{
		// MyTest res;
		// res.x = other.x;
		// res.y = other.y;
		// return res;

		x = other.x;
		y = other.y;
		return *this;
	}

	void printData()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
		cout << endl;
	}
};


int main()
{
	MyTest c1(10, 20);
	MyTest c2(20, 50);
	MyTest c3;

	c3 = c1 + c2;
	c3.printData();   // x : 10 + 20 = 30 ���
	                  // y : 20 + 50 = 70 ���

	MyTest c4;
	c4 = c2 - c1;
	c4.printData();   // x : 20 - 10 = 10 ���
	                  // y : 50 - 20 = 30 ���

	MyTest obj;
	obj = c1.operator=(c2);

	return 0;
}