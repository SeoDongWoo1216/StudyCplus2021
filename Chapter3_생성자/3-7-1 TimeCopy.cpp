#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime()
	{
		printf("���� �ð��� %d:%d:%d �Դϴ�. \n", hour, min, sec);
	}
};

int main() 
{
	Time now(12, 34, 56);
	Time then = now;

	then.OutTime();
}

/*
�츮�� ���� Ŭ������ ���θ��� �ڷ����̶� �� �� �ִ�.
�츮�� ���� Ŭ������ �������ִ� �ڷ����� ��� ���ó�� �Ȱ��� ����Ǿ���Ѵ�.
���� Ŭ������ ���簡 �����ؾ��Ѵ�.
�� �ǳ�? �ڵ������� ��������ڰ� ȣ��Ǳ� ������ �ڵ������� �ʵ��� ������ �����ؼ� ����ؼ�
������ Ÿ���� ��ü�� ���� ����ϴ°� �����ϴ�.

*/