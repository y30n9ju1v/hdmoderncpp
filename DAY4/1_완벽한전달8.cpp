#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// �ٽ� : ���� �Ѱ� �� �Ϻ��� ������ �Ϸ���
// 1. ���ڸ� ������ "T&&" �� �������� - forwarding reference
// 
// 2. ���ڸ� �ٸ� �Լ��� ����(forward) �Ҷ� 
//    "std::forward<T>(arg)"�� ��� ��������. 
//	  "static_cast<T&&>(arg)" �� �ص� �˴ϴ�.
// 
//	  => �ʿ��� ���� : rvalue �� chronometry�� �����µ�.. 
//				     �����鼭 lvalue(arg) �� �Ȱ��� 
//				     �ٽ� rvalue �� �����ϱ� ���Ѱ�


template<typename F, typename T>
void chronometry(F f, T&& arg)
{	
	f( std::forward<T>(arg) ); 
}


int main()
{
	int n = 0;
	chronometry(goo, n);	
	chronometry(foo, 10);	
}
