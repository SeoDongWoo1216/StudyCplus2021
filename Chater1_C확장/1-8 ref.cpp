#include <stdio.h>

int main() 
{
	int i = 3;
	int& ri = i;

	printf("i = %d, ri = %d\n", i, ri);
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	printf("i���� = %x, ri���� = %x\n\n", &i, &ri);

	// pi�� �����͸� �ǵ������
	int* pi;
	pi = &i;

	printf("pi�� �� : %d, pi�� �ּ� : %p\n", pi, &pi);
	printf("pi�� ����Ű�� �� : %d\n", *pi);

	*pi = i + 1;
	printf("pi�� �� : %d, pi�� �ּ� : %p\n", pi, &pi);
	printf("pi�� ����Ű�� �� : %d\n", *pi);
}