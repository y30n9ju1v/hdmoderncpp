#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// args ���� 2��° ��Ҹ� �ѹ��� ������ ����� �����ϴ�.

	// 1. pack expansion �� ����ϰų�
	// 2. ��� ȣ�� ���� ����� ����Ҽ� �ۿ� �����ϴ�.


	// ��� ����� Ÿ���� ������ "�迭 ���� ���� ��������"
	int x[] = { args... };

	// Ÿ���� �ٸ��� "tuple" �� ��������
	std::tuple<Types...> t(args...);

	// �׷���, ���������� "��� ��Ҹ� �������� ���� �����ϴ�."
	// => ���� ����.
}


int main()
{
	foo(1, 2, 3);
}

