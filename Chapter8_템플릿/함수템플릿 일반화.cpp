/* �Լ� ���ø� : �Լ��� Ʋ�� ���� �������� �ڷ����� ������ ������ ���������.*/
#include <iostream>
using namespace std;

template<typename T>  // ���� �⺻���� ���ø� ����
T Add(T a, T b)
{
	return a + b;
}


int main()
{
	cout << Add(10, 20) << endl;    // ������ �Ǽ��� Add�� ���� �� ���� ���� ��ȯ���� �� ����.
	cout << Add(3.14, 4.5) << endl;  
	return 0;
}