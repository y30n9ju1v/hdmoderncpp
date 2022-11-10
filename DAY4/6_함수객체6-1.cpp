#include <iostream>
#include <algorithm>
#include <string>

// 사용자가 C++ 표준과 동일한 이름의 함수를 만들었다고
// 생각해 봅시다.
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
