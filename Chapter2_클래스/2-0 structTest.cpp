#include <iostream>

class Human         // ����ü�ʹ� �ٸ��� Ŭ������ ��� ���� + �Լ� ����
{
public:             // ������ Ŭ���� ��������� public�� ����������.
	// ��� ���� ����
	char name[20];
	int age;
	float height;
	float weight;
	char blood;

	void view();

};

void Human::view()  // �����Լ��� Human Ŭ������ �ҼӵǾ������� ǥ������.(�������������� '::' ���)
{
	printf("�̸�   : %s\n", name);
	printf("����   : %d\n", age);
	printf("����   : %.2f\n", height);
	printf("ü��   : %.2f\n", weight);
	printf("������ : %c\n", blood);
}

int main() 
{
	Human my = { "ȫ�浿", 30, 190, 100, 'A' };

	my.view();  // Ŭ������ �ִ� �Լ� ȣ��

	return 0;
}