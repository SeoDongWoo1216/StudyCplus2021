#include <stdio.h>

class Some
{
private:
	mutable int temp; // const �Լ� �ȿ��� ������ �� �ְ� ���ִ� mutable ����

public:
	Some() {}
	void method() const { temp = 0; }  // const�ȿ��� temp�� ���� �����Ϸ����ߴµ� �����ȶ�
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();
}