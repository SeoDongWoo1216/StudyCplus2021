#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// ���ʹ� �迭�� ���¸� �������ְ�, ���� ���Ǽ��� �������ش�.
	vector<int> v = { 10,20,30,40,50 };

	// �迭�� ����Ҷ�ó�� 1����� ���
	for (auto i = 0; i < v.size(); i++)  // v.size() : ������ ũ��
		                                 // auto�� �����ϸ� � Ÿ���̵� ���� �� ����
	{
		cout << v[i] << ' ';
	}

	cout << endl;

	for (auto iter = v.begin(); iter != v.end(); iter++)  // iter�� v�� ���ۺ��� iter�� v�� �������ɶ�����
	{
		cout << *iter << ' ';   // iter�� �������̹Ƿ� *iter�� ǥ��
		                        // �迭�� �Ƚ��൵ �迭�� ��µǴ� ȿ���� �� �� ����.
	}

	cout << endl;

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << ' ';      // �츮�� ���� ǥ���
	}



	return 0;
}