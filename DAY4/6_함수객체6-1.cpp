#include <iostream>
#include <algorithm>
#include <string>

// 사용자가 C++ 표준과 동일한 이름의 함수를 만들었다고
// 생각해 봅시다.
/*
template<typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}
*/
struct MaxFn
{
	template<typename T>
	const T& operator()(const T& a, const T& b) const
	{
		return a < b ? b : a;
	}
};

MaxFn max; // max 는 함수 가 아닌 함수 객체 입니다.

int main()
{
	int ret1 = max(1, 2);	// 1, 2 는 std 안에 있는 타입아닙니다.							
							// 사용자가 만든 max 사용

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); // max 가 함수 라면 에러(ADL 때문)
							// 함수객체는 ADL 을 적용하지 않습니다.
							// 사용자가 만든 max 사용
}
