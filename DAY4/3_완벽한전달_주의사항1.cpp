// 9_�Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0
{								// foo(arg) �� ����! 					

								// std::nullptr_t&& arg = nullptr;
								// foo(arg) �� ok..
	f(std::forward<T>(arg));
}

// �ٽ� : �Ϻ��� ������ ����� ����ϴ� �Լ��� �����Ͱ��� ��������
//      "0" �� ����ϸ� ���� �Դϴ�.
//	    �ݵ�� "nullptr" �� ����ϼ���

void foo(int* p) {}

int main()
{
	foo(0); // ok

//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok

}









