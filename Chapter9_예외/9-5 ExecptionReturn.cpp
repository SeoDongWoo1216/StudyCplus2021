#include <stdio.h>

int report()
{
	if (true /*���ܹ߻�*/) return 1;

	// ������� ������ ������ �۾� �Ϸ�
	return 0;
}

int main()
{
	int e;

	e = report();
	switch (e)
	{
	case 1:
		puts("�޸𸮰� �����մϴ�.\n");
		break;
	case 2:
		puts("���� ������ �ʰ��߽��ϴ�.\n");
		break;
	case 3:
		puts("�ϵ� ��ũ�� ��� á���ϴ�.\n");
		break;
	default:
		puts("�۾��� �Ϸ��߽��ϴ�\n");
		break;
		
	}
}