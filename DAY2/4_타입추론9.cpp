#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4); // auto �� �캯�� ������
//  int  ret = foo(1, 3.4); // �����ϰ� Ÿ�� ����


//	decltype( �Լ� ȣ��� ) : �Լ� ȣ���� ����� ������ Ÿ��.
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//  int& ret = foo(1,3.4);


	// decltype(auto) : C++14���� �߰��� ǥ���
	// => auto �ڸ��� �캯 ǥ������ �־� �޶�.
	// => �Ǵ�, �캯���� Ÿ���� �����ϴµ�, ��Ģ�� decltype ��Ģ ����
	decltype(auto) ret3 = foo(1, 3.4);
//  int& ret3 = foo(1, 3.4);


	// ����
	// �򰡵��� ���� ǥ����(unevaluated expression)
	// (A) : ���� ����Ǵ� ���� �ƴϰ�, ������ �ð��� �Լ� ������ ã�Ƽ�
	//       ��ȯ Ÿ�Ը� ���� - �򰡵��� ���� ǥ����
	// (B) : ����ð��� ���� ����˴ϴ�.
	//			(A)					(B)
	decltype(foo(1, 3.4)) ret5 = foo(1, 3.4);

	// C++���� 4���� �򰡵��� ���� ǥ������ �ֽ��ϴ�.
	// => �򰡵��� ���� ǥ���Ŀ� ���� �Լ��� ���� �־ �˴ϴ�.
	decltype(foo(1, 3.4)) d;

	bool b = noexcept(foo(1, 3.4));

	int n = sizeof((foo(1, 3.4));
	
	typeid(foo(1, 3.4)).name();
}

// int goo(int a);
// int n = sizeof(goo(3)); // 4. ���� �ƴ�. ���� ���� �˼� ����.

