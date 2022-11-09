#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

template<typename T>
void Swap(T& a, T& b)
{
	// 깊은 복사에 의한 swap 
	// 성능이 좋지 않습니다.
//	T tmp = a;
//	a = b;
//	b = tmp;

	// 자원 이동에 의한 swap
	// 위 코드보다 빠릅니다.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}



