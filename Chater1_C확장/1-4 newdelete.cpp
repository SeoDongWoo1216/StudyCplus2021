#include <stdio.h>

int main() 
{
	int* pi, *pj;

	pi = new int;
	pj = new int(10);    // �޸𸮿� �Ҵ��ϸ鼭 �ʱ�ȭ

	*pi = 123;           // �Ҵ��� �Ŀ� �ʱ�ȭ
	
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;
	delete pj;
}