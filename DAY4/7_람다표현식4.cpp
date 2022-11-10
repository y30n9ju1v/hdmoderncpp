// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

// ����ǥ���İ� Ÿ��

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{ operator()()}; xxx();


	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{ operator()()}; yyy();

	// �ٽ� 1. ��� ����ǥ������ "�ٸ� Ÿ��" �Դϴ�.

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// �ٽ� 2. ���� ǥ�������� �ʱ�ȭ�� auto ������ ����ɼ� �����ϴ�
	
	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error
				// ���� ���� ǥ�����̶� Ÿ���� �ٸ��Ƿ�

	// �ٽ� 3. �߿�!!
	int x[3] = { 1,2,3 };

	// �Ʒ� ó�� ����ϸ� 3���� ���ٰ� ��� �ٸ� Ÿ�� �̹Ƿ�
	// "3���� for_each�� ����" �� �����˴ϴ�.
	std::for_each(x, x + 3, [](int n) { std::cout << n; });
	std::for_each(x, x + 3, [](int n) { std::cout << n; });
	std::for_each(x, x + 3, [](int n) { std::cout << n; });

	// �ذ�å : ������ ���� ǥ������ ������ ���ȴٸ�
	// auto ������ ��Ƽ� ����ϼ���
	auto show = [](int n) { std::cout << n; };

	std::for_each(x, x + 3, show );
	std::for_each(x, x + 3, show );
	std::for_each(x, x + 3, show );

}






