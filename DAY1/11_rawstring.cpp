// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// �Ϲ� ���ڿ� : "\" �� Ư�� ���ڷ� �ؼ�
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : "\" �� �Ϲ� ���ڿ��� �ؼ�
	std::string s2 = R"(\\\\.\\pipe\\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}