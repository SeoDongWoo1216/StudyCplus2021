#include <stdio.h>

class MathCalc
{
private:
	const double pie;  // const ��� ���� => ���ȭ => ����� ���ÿ� �ʱ�ȭ

public:
	MathCalc(double apie) : pie(apie) { }  // �ݷ� �ʱ�ȭ

	// pie�� const�� ������ ���ο��� �ʱ�ȭ�� �� ����.
	// �ʱ�ȭ �Ǳ����� �����ڿ��ٰ� �ݷ� �ʱ�ȭ�� �����־���.
	// ��� ��� ������ �ʱ�ȭ �����ִ� ����
	 
	// ��ü�� �����Ǵ� ����
	// ��ü�̸����� �޸� �Ҵ� -> ������ ȣ��, �ʱ�ȭ
	                                      
	void DoCalc(double r)
	{
		printf("������ %.2f�� ���� �ѷ� : %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}