#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// ���������ͷ� �Ű����� ����
//void InputName(char** Name)  
//{
//	*Name = (char*)malloc(32);
//	strcpy(*Name, "Hong Kil Dong");
//}
//
//int main() 
//{
//	char* Name;      // ������ ����
//
//	InputName(&Name); 
//	printf("�̸��� %s�Դϴ�.", Name);
//	free(Name);
//}

//// ���۷����� �Ű����� ����
//void InputName(char*&Name)       
//{
//	Name = (char*)malloc(32);
//	strcpy(Name, "Hong Kil Dong");
//}
//
//int main()
//{
//	char* Name;      // ������ ����
//
//	InputName(Name);
//	printf("�̸��� %s�Դϴ�.", Name);
//	free(Name);
//}


int main() 
{
	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p\n", &a, &ra, pa);
	// &a  : a�� �ּҰ�
	// &ra : ���۷��� ���� a�� �ּҰ�
	// *pa : pa�� ra�� ����Ű���ִµ� &ra�� a�ϱ� a�� �ּҰ� ����
	
	// ����Ű��ϸ� �ֹε�Ϲ�ȣ�� �޴´�.
	// ���۷����� �ֹε�Ϲ�ȣ���ƴϰ� �׳� ������.

	// ���۷��� �迭�� ������ �� ����.

	// ���۷����� ��ø�� �� ���� �����ͳ� �迭���� �Ļ����� ���� �� ����
	// ���۷����� �Լ����������� �Ű������� ����Ҷ� ����Ѵ�.
	// �Լ������� ���������� �ǵ帱�� ���۷����� ����ϸ� �����͸� ����ϴ� ȿ���� ����.
	/
}