#include <stdio.h>

// template<typename T>   // Ŭ���� ���ø� => ���ø� ������ �����β����� Ŭ������ �����Ƿ� ������
                          // ���ø���ü�� Ŭ������ �ɼ����� ���ø��̸��ϻ���.


class Util
{
public:
	template<typename T>   // ���ø��Լ� ����
	void swap(T& a, T& b)
	{
		T t;
		t = a;
		a = b;
		b = t;
	}
};

int main()
{
	//Util<int> u1;    // ���ø� Ŭ������������
	//Util<double> u2;

	Util u;
	int a = 3;
	int b = 4;
	double c = 1.2;
	double d = 3.4;
	char e = 'e';
	char f = 'f';

	u.swap(a, b);
	u.swap(c, d);
	u.swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}