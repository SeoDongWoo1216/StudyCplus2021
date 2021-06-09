// 예외지정 : 실행하면 프로그램이 뻑감
#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("발생해서는 안되는 에러 발생");
	exit(-2);
}

void calc() throw(int)
{
	throw "string";
}

int main()
{
	set_unexpected(myunex);
	try
	{
		calc();
	}
	catch (const char* message)
	{
		puts("문자열 예외 발생");
	}

	catch (int)
	{
		puts("정수형 예외 발생");
	}
	puts("프로그램 종료");
}