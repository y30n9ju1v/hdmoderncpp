#include <iostream>
#include <algorithm>
#include <string>

// ����ڰ� C++ ǥ�ذ� ������ �̸��� �Լ��� ������ٰ�
// ������ ���ô�.
template<typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	int ret1 = max(1, 2);								

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); 
}
