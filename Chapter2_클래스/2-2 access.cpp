#include <stdio.h>

struct SHuman   // ĸ��ȭ, �߻�ȭ�� ���÷ε� �� �� �ִ�.
{

private:             // private�� ���� ����
	char name[20];
	int age;

public:
	void intro() 
	{
		printf("�̸� : %s\n", name);
		printf("���� : %d\n", age);
	}
};

int main() 
{
	SHuman kim;

	// kim.age = 300;  // ��������� private�̱⶧���� �ܺο����� ������ �� ����. (����)

	kim.intro();  // public ���� �����߱⶧���� �ܺο��� ȣ�Ⱑ��.
}