// 3_�ʱ�ȭ4-1
#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // ����ڰ� 'a' �� �Է� �߽��ϴ�.

	std::cout << n << std::endl; // 1. 97
								 // 2. 10
								 // 3. 0  => ��! �Է� ����!
								 // 4. -1

	// �Է� ���и� �����ϴ� ��� 1.  fail ��� �Լ� ���
	if ( std::cin.fail() ) {}

	// ��� 2. cin ��ü�� if ���� ������ �ֽ��ϴ�.
	// => ��ü�� scalar test ��� �մϴ�.
	if (std::cin)
	{
		// �Է� ������ ���.
	}
}


