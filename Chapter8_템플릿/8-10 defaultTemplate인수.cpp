#include <iostream>
using namespace std;


template <typename T, int sz>
class CTest
{
private:
	T ary[sz];
	int num;

public:
	T& operator[](int idx)             // ��ü���� �迭[] �� [] �����ڴ� ���ǵǾ����� �����Ƿ� [] ������ �����ε�
	{
		if (idx < 0 || idx >= sz)      // �迭�� ũ�⸦ ������� ����
		{
			cout << "�迭�� ũ�⸦ ������ϴ�" << endl;
			exit(1);
		}
		return this->ary[idx];
	}

	void getData()
	{
		for (int i = 0; i < sz; i++)
		{
			cout << ary[i] << endl;
		}
	}
};

int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	arr.getData();
	return 0;
}