#include <iostream>
using namespace std;


class Base
{
private:
	int data;
public:
	Base() {};
	~Base() {};
	void setData(int data)
	{
		this->data = data;
	}
	int getData()
	{
		return this->data;
	}
};


class Derived : public Base
{
public:
	void setData(int data)
	{
		if (data > 0)
		{
			data = 0;
		}
		Base::setData(data);
	}
	void printData()
	{
		cout << "printData() : " << getData() << endl;
	}
};

int main()
{
	Base* pb = new Derived;
	Derived* pd = NULL;

	pb->setData(10);      // �θ�Ŭ������ setData ȣ��
	// pb->printData();

	pd = static_cast<Derived*>(pb);  // static_cast�� �̿��ؼ� �ڽ�Ŭ������ ����ȯ
	pd->setData(20);      // �ڽ�Ŭ������ setData ȣ��
	pd->printData();

	return 0;
}

