// �� ���� �ٲٴ� swab �Լ� ����(���۷��� ���))
#include <iostream>
using namespace std;

void ref_swab(int &a, int &b);

int main() 
{
	int a = 10;
	int b = 20;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	
	ref_swab(a, b);              // �����Ͱ����� �ƴ϶� �׳� ���μ��� ����

	cout << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}

void ref_swab(int &x, int &y)   // �Ű������� ���۷����� ����
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}