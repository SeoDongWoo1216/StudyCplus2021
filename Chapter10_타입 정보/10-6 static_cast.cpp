#include <stdio.h>

int main()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1, 2, 3, 4, 5 };
	char aary[] = { 'a', 'b' };

	int* ptr = static_cast<int*>(ary);  // �迭�� int������ �ٲ� �� �ִ�.
	//ptr = static_cast<int*>(aary);    // �����ͳ����� ����ȯ => ����

	i = static_cast<int>(d);        // ����
	//pi = static_cast<int*>(str);  // ���� : static_cast�� �����ͳ��� ����ȯ�� ����������.
	pi = (int*)str;                 // ����
}