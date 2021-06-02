#include <stdio.h>

class DBQuery
{
private:
	static int hCon;
	int nResult;

public:
	DBQuery() {};
	static void DBConnect(const char* Server, const char* ID, const char* Pass);
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};


int DBQuery::hCon;  // ���� ����� �ʱⰪ�� ���൵ �ڵ����� 0���� �ʱ�ȭ�� �ȴ�.


void DBQuery::DBConnect(const char* Server, const char* ID, const char* Pass)
{
	// ���⼭ DB ������ ����
	hCon = 1234;
	puts("����Ǿ����ϴ�.");
}

void DBQuery::DBDisConnect()
{
	// ��������
	hCon = NULL;
	puts("������ ���������ϴ�.");
}

bool DBQuery::RunQuery(const char* SQL)
{
	// Query(hCon, SQL);
	puts(SQL);
	return true;
}

int main()
{
	DBQuery::DBConnect("Secret", "Adult", "�ֵ�������");
	DBQuery Q1, Q2, Q3;

	// �ʿ��� DB ���Ǹ� �Ѵ�.
	Q1.RunQuery("select * from tblNuja where ���� ģ�� ���");

	DBQuery::DBDisConnect();
}
