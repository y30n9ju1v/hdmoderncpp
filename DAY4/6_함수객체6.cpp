#include <iostream>
#include <algorithm>
#include <string>

// �Լ� ��ü ���� 3. ADL ��Ģ�� ������� �ʴ´�.
//				=> ���� ���ٴ� Ư¡!

int main()
{
	int ret1 = max(1, 2);
	int ret2 = std::max(1, 2);

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); // ��.. ������ ������� ?
}