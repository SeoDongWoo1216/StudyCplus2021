#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;                       // �迭���� ����ϴ°���
	vector<int> v1 = { 1, 2, 3, 4, 5 };  // �ʱⰪ�� �����ؼ� �ʱ�ȭ����
	vector<int> v2[5];                   // 5���� ���� ���� v2 ����

	v.push_back(10);  // ������ ���Ϳ��� �Ǹ����� ��ҿ� 10�� �߰�
	
	vector<int> ::iterator iter = v.begin();  // ���ͷ����� ����� : �����Ͱ��� ��ü
	                                          // iter��� iterator Ÿ���� ��ü ����(������ ���� ��ü)
	                                          // iter�� ������ v�� ������ �� ����

	iter = v.insert(iter, 2);  // v�� �� ó���� 2 ����

	v.pop_back();     // v�� �� ���������ִ� ��� ����

	v.erase(v.begin() + 10);   // v�� ù��°���� �����ؼ� 10��°������ ��Ҹ� ����

	v.clear();        // v�� ��� ���� ����


	return 0;
}