// Ŭ���� ���ø�
#include <iostream>
using namespace std;

template <typename T>
class CTest
{
private:
	T num;
public:
	// CTest(T anum) : num(anum) { };
	CTest(T);             // ����
	void printData()
	{
		cout << "num : " << num << endl;
	}
};

template <typename T>     // ���ø����� ������ �ѹ� �� ���ֱ�
CTest<T>::CTest(T anum)   // �����ڸ� �ܺο��� �����Ϸ��� �̷��� �ؾ���.
{

}


int main()
{
	// CTest obj(10);     // Ŭ�������ø��� <typename> �� �����ϸ� ����
	CTest<int> obj(10);
	obj.printData();
	return 0;
}