#include <iostream>
using namespace std;
class CTest
{
public:
	CTest() { cout << "CTest()" << endl; };
	~CTest() { cout << "~CTest()" << endl; };
	void func() { cout << "func()" << endl; }
};

int main()
{
	//shared_ptr<CTest> ptr1(new CTest);  
	//ptr1->func();

	//cout << "count : " << ptr1.use_count() << endl;  // �ټ����� �޸𸮸� �����Ҵ��� �� �ְ� ����
	//{
	//	shared_ptr<CTest> ptr2(ptr1);
	//	cout << "count : " << ptr1.use_count() << endl; // �������� porting ����
	//	ptr2->func();
	//}
	//cout << "count : " << ptr1.use_count() << endl;
	


	unique_ptr<CTest> ptr1(new CTest);  //�ϳ��� porting �Ҽ�����(auto_ptr�� �����ģ����) => ����Ʈ������


	return 0;
}