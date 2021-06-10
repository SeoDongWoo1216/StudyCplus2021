#include <iostream>

class A
{
public:
	virtual void test() { printf("A::test()\n"); }
};

class B : public A
{
public:
	virtual void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }
};

class C : public B
{
	virtual void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};

void GlobalFunc(A& a)
{
	try
	{
		C& c = dynamic_cast<C&>(a); 
		printf("GlobalFunc()\n");
	}
	catch(std::bad_cast)
	{
		printf("casting error\n");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;

	pa->test();                     // C�� test() ���
	
	B* pb = dynamic_cast<B*>(pa);   // �ٿ�ĳ����
	if (pb) pb->test2();            // B�� test() ���
	
	C* pc = dynamic_cast<C*>(paa);  // paa�� �����δ� B�ε� ����ȯ������ C�� ����Ű������ => �ڽ��� �θ𸦰���Ŵ
	                                // ���� �̰��� ��ĳ����
	// if (pc) pc->test2();

	C c;
	GlobalFunc(c);      // GlobalFunc ���

	B b;
	GlobalFunc(b);      // ĳ���� ����

	return 0;
}