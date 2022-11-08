#include <iostream>
#include <type_traits>
// ��Ģ 3�� ����
// 
// ��Ģ 1. ��Ÿ������ ������
//  �Լ������� "const, volatile, reference"������ T����
//  T�� Ÿ���� �ᱹ a�� Ÿ��
template<typename T> void foo(T a)
{
	
}
// ��Ģ 2. ������ ������
// �Լ������� "reference" ������ T�� Ÿ�� ����
// const, volatile�� ����
// T�� �����Ǹ� & �� �ٿ��� a�� Ÿ�԰���
// T�� int ��� a�� int&

template<typename T> void goo(T& a)
{
}

// ��Ģ 3. forwarding reference �϶� - ���� �ð��� �ٷ�ϴ�.
template<typename T> void hoo(T&& a)
{
	// ������ �ð��� Ÿ�Կ� ���� ���� ����
	bool b1 = 
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}