// ��øŬ����
// �����̸� : NestClass.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Product // �ܺ� Ŭ����
{
private:
	char name[64];
	char company[32];
	int price;


	class Date // ���� Ŭ����(inner Ŭ����)
	{
	protected:
		int year, month, day;

	public:
		Date(int y, int m, int d) { this->year = y; this->month = m; this->day = d; }
		void OutDate() { printf("%d/%d/%d", year, month, day); }
	};


	Date validto;
public:
	Product(const char* name, const char* company, int y, int m, int d, int price) : validto(y, m, d)
	{
		strcpy(this->name, name);
		strcpy(this->company, company);
		this->price = price;
	}

	void OutProduct()
	{
		printf("�̸�     : %s\n", this->name);
		printf("������   : %s\n", this->company);
		printf("��ȿ�Ⱓ : ");
		validto.OutDate();
		puts("");
		printf("����     : %d\n", this->price);
	}
};

int main()
{
	Product shrimp("�����", "���", 2020, 8, 15, 900);
	shrimp.OutProduct();

	// Date now(12, 34, 56);   // ����
}