// xvalue
#include <string>

std::string foo()
{
	std::string s = "aaa";
	return s;
}

int main()
{
	std::string s1 = "bbb";
	std::string s2 = "ccc";

	// �Ʒ� 3���� �������� ������ ���ô�.
	// 1. copy ? move ����
	// 2. ��ü�� �ı� ����
	//									1			2
	std::string s3 = s1;			//
	std::string s4 = std::move(s2);	//
	std::string s5 = foo();			//
}