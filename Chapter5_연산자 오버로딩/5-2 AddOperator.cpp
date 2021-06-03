#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime()
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}

	// operator Ű���带 ���̰� '+'�� �Լ� �̸����� ���°���
	// ���� const�� ��°��� ����Ǹ� �ȵȴٴ� �ǹ�.
	// ���� const�� ��� �������� ���ȭ ������.
	const Time operator + (const Time& other) const  
		// �ٸ� ��ü�� �ҷ����µ� ��ü�� �Ű������� ���Ƿ��� ���۷����� ����;���
	{
		// ���� const�� �ٿ��µ��� ������ ����ǰ�, ������ �ȶ� => t1�� hour, min, sec�� ���ȭ��Ű�� ����

		// Time t�� ���� �����ִ� �Լ��ȿ��� ������ ���̶� ���ȭ�� ����ȵ�.
		// other�� �������� ���� t2�� ������

		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;

		t.hour += t.min / 60;
		t.min %= 60;
		return t;     // t�� Ÿ���� Time
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;  // ��ü + ��ü�� ǥ�Ⱑ ��������.
	// t3 = t1.operator+(t2);   // ������ �Ȱ��� �ڵ���.
	// t3 = t1.AddTime(t2);     // �Ϲ� �Լ� ȣ���Ҷ� �ڵ�
	t3.OutTime();
}