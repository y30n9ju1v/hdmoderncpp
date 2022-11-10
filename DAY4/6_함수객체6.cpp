#include <iostream>
#include <algorithm>
#include <string>

// 함수 객체 장점 3. ADL 규칙이 적용되지 않는다.
//				=> 장점 보다는 특징!

int main()
{
	int ret1 = max(1, 2);
	int ret2 = std::max(1, 2);

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); // 왜.. 에러가 없을까요 ?
}