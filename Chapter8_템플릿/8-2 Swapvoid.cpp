#include <stdio.h>
#include <malloc.h>
#include <memory.h>


// ���α׷��� ����ɶ� Ÿ���� ������ => �������ε�
// �Լ��� �Ϲ�ȭ
void swap(void *a, void *b, size_t len)
{
	void* t;
	t = malloc(len);
	memcpy(t, a, len);   // �޸𸮿� �ִ� ������ ī���ϴ� �Լ�
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3;
	int b = 4;

	double c = 1.2;
	double d = 3.4;

	swap(&a, &b, sizeof(int));      // void* Ÿ���̶� ũ�⵵ ���ڷ� �����ؾ���.
	swap(&c, &d, sizeof(double));

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f", c, d);
}