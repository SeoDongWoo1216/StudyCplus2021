// ũ�Ⱑ 100�� �Ǽ��� �迭�� �Ҵ��ϰ� 50��° ��ҿ� 3.14�� �����Ͽ� ���

#include <stdio.h>

int main() 
{
	double* ar;
	ar = new double[100];
	ar[50] = 3.14;
	printf("ar[50] : %.2f \n", ar[50]);
}