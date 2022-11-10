// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// main					chronometry					hoo(int&&)
// hoo(10) =============================================> ok
// chronometry(10)  ====> int&& arg�� �ޱ�
//					      hoo(arg) =====================> error
//						  hoo(static_cast<int&&>(arg))==> ok.

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	// ���ڸ� ������ 
	// "int&& arg = 10" �ε�. �̶� "10" �� rvalue ����
	//						 arg �� "lvalue" �Դϴ�.
//	f(arg);	// hoo(int&) �� ã�� �˴ϴ�.

	// ���� ���ڴ� "rvalue" ���µ�, �����鼭 �̸��� ���ܼ� lvalue ���Ȱ�
	// �Լ��� �����Ҷ��� �ٽ� rvalue �� �����ؼ� �����մϴ�.
	f(static_cast<int&&>(arg)); // hoo(int&&) �� ����
}

int main()
{
	hoo(10); 
	chronometry(hoo, 10); 
}
