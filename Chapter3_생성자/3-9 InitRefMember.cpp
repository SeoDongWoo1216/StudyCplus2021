#include <stdio.h>

class Some
{
public:
	int& total;
	int n1, n2;


	// �Ϲ����� �������� �ʱ�ȭ
	//Some(int n1, int n2)
	//{
	//	this->n1 = n1;
	//	this->n2 = n2;
	//}

	// total�Ӹ��ƴ϶� �ٸ� ���ڸ� �޾������� �̷��� �ʱ�ȭ�� �� ����.
	// Some(int& atotal, int on1, int on2) : total(atotal), n1(on1), n2(on2) {}


	Some(int& atotal) : total(atotal) {}


	void OutTotal() { printf("%d\n", total); }
};

int main() 
{
	int value = 8;
	Some S(value);
	S.OutTotal();
}