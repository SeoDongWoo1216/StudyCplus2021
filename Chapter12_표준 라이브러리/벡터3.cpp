#include <iostream>
#include <vector>     // ���� �������
#include <algorithm>  // sort �������
using namespace std;

bool compare(int a, int b) { return a > b; }  // ���� ����(���ʰ�)�� ũ�� ����(��������)

int main()
{
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	for (auto i = arr.begin(); i < arr.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;

	//sort(arr.begin(), arr.end());        // arr�� ���ۿ��� ������ ����(����Ʈ�� ��������)

	sort(arr.begin(), arr.end(), compare);  // return ���� ���ؼ� �����ض�.
	                                        // �������� ����

	for (auto i = 0; i < arr.size(); i++)   // auto�� ���� �ڵ����� �����Ϸ��� �ڷ����� ������
	{
		cout << arr[i] << ' ';
	}

	return 0;
}