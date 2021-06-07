#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int num)
	{
		this->num = num;
		cout << this->num << " CTest ������ ȣ��" << endl;

	}

	virtual ~CTest()
	{
		cout << this->num << "CTest �Ҹ��� ȣ��" << endl;
	}

	virtual void func()
	{
		cout << "CTest function()" << endl;
	}

};


class CTestSub : public CTest
{
private:
	int subN;
public:
	CTestSub(int num, int subN) : CTest(num)
	{
		this->subN = subN;
		cout << this->subN << " CTestSub ������ ȣ��" << endl;
	}

	~CTestSub()
	{
		cout << this->subN << " CTestSub �Ҹ��� ȣ��" << endl;
	}

	void func()
	{
		cout << "CTestSub function()" << endl;
	}

};


int main()
{
	CTest b(10);
	b.func();
	cout << endl;

	CTestSub d(10, 20);
	d.func();
	cout << endl;

	CTest* pb = new CTestSub(30, 33);  // �θ�ü�� �ڽİ�ü�� ����Ű�� �����ͷ� ����
	                                  // �߻��ڷ������� �ڽİ�ü�� ����Ű����.
	pb->func();                       // �θ𲨰� �����Լ� �Ǿ������� �ڽ� func ȣ��
	                                  // �θ𲨰� �����Լ� �ȵǾ������� �θ� func ȣ��
	cout << endl;

	delete pb;

	return 0;
}