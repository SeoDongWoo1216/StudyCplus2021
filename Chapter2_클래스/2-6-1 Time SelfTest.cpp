/*
��, ��, ���� ����� ������ Time Ŭ������ �����ϵ���
��, ��, ���� ����� ������ Date Ŭ������ �����϶�.
���� ��¥�� ����ϴ� ��� �Լ��� �����Ѵ�.
*/

#include <stdio.h>

class Date
{
private:
	int year, mon, day;

public:
	void SetDate(int y, int m, int d)
	{
		year = y;
		mon = m;
		day = d;
	}

	void OutDate() 
	{
		printf("���� ��¥�� %d�� %d�� %d�� �Դϴ�.\n", year, mon, day);
	}
};

int main() 
{
	Date now;

	now.SetDate(21, 05, 31);
	now.OutDate();
}