// 8_nullptr2
#include <iostream>

// �� nullptr�� ������� ?

template<typename F, typename T>
void forward_argument(F f, T arg)	// int arg = 0; �϶�
{									// foo(arg) �̹Ƿ� ����
									// std::nullptr_t arg = nullptr
	f(arg);							// foo(arg) �� ok.. 
}
void foo(int*) { std::cout << "foo" << std::endl; }

int main()
{
	foo(0);	// ok

	int n = 0;
//	foo(n); // error. ���ͷ� '0' �� �����ͷ� �Ͻ��� ����ȯ ������
			// 0���� �ʱ�ȭ�� ������ ������ �����ͷ� �Ͻ��� ��ȯ�ɼ�
			// �����ϴ�.

//	forward_argument(foo, 0); // �ǵ� "foo(0)" ó�� ȣ���� �޶�
							  // ������ ����!!!
	forward_argument(foo, nullptr); // ok
}







