// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// �Ʒ� ������ �� �Ѱ����� ������ �ֽ��ϴ�... 
// main �Լ��� �ڵ尡 �� �������� ������ ������.
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // �� �����ϱ�� ???
						  	
}
