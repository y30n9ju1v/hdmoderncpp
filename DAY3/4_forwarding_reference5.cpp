#include <iostream>

template<typename T> void foo(T&& arg)
{
	// Ȯ���ϴ¹� - �Ʒ� ó�� �ص� �ǰ�
	std::cout << __FUNCSIG__ << std::endl;

	// godbolr.org�� ���ڵ带 �־� ������..
}

int main()
{
	int n = 10;

	// forwarding reference ����
	// ���ڿ� ���� T �� � Ÿ���� �Ǵ��� ��Ȯ�� �˾ƾ� �մϴ�.
	foo(n);  // T=int&    arg : T&& => int& && => int&
	foo(10); // T=int     arg : T&& => int&&
}




