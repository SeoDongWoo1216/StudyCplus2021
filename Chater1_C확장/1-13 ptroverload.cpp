#include <stdio.h>

void sub(int a)
{
	printf("int : %d\n", a); 
}

void sub(int* a)
{ 
	printf("pointer:%p\n", a); 
}

int main() 
{
	int i = 1234;
	int* pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);        // NULL�� �ּҰ��� �������ִµ� ���� �ڵ忡���� �����Ϸ��� int�� �ν�����
	sub((int*)NULL);  // NULL�� ���� ����ȯ


	// NULL�� ������ 0�� ��Ÿ���µ� �ƹ��͵� ����Ű���ʴ� �ּҸ� ������ �� �ִ� �����ʹ�.
	// ��� �ϱ����ؼ��� NULL�� ��������ȯ(�ּ����� ��Ÿ����)�� �������.

	// �����ε��� ���ϱ��ѵ� �������̸� �ߺ����Ǹ� �����ʴ� ���� ����.
}


