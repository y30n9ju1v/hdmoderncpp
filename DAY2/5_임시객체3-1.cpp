// 5_임시객체3-1
#include <iostream>
#include <string>

// max 를 만들어 봅시다.
// 1. 복사본없이, 임시객체도 받으려면 "const &"
// 2. 반환 값도 복사본없으려면 const &
template<typename T> 
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}
int main()
{
	int n = max(3, 4);

	std::string s1 = "A";
	std::string s2 = "B";

	const std::string& ret1 = max(s1, s2);
	// ret1은 결국 s2를 가리킵니다.
	// 항상 안전 합니다.

	const std::string& ret2 = max(std::string("aaa"),
								  std::string("bbb"));
	// ret2는 안전할까요 ?
	// ret2 는 "dangling reference" 입니다. 사용하면 안됩니다.
	// 임시객체의 수명연장은 "최초의 참조" 한번만 가능합니다.

	// cppreference.com 에서 "std::max" 검색해 보세요.
	// "Notes" 읽어 보세요.
}
