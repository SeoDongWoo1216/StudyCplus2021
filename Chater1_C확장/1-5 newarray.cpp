#include <stdio.h>

int main() 
{
	int* ar;

	ar = new int[5];
	// ar = (int*)malloc(sizeof(int) * 5)  // C������ �迭 �����Ҵ�

	for (int i = 0; i < 5; i++) 
	{
		ar[i] = i;
	}
	for (int i = 0; i < 5; i++) 
	{
		printf("%d��° = %d\n", i, ar[i]);
	}
	delete[] ar;
}