// 5_range_for4 - 1번 복사해오세요
#include <iostream>
#include <vector>

// 아래 클래스를 잘 생각해 보세요
// => C++20 부터 등장하는 "시각(View)" 입니다.
// => C++20 "Range" 라이브러리의 원리
template<typename T>
class reverse_view
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); } // 핵심!!!
	auto end()   { return range.rend(); }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	reverse_view rv(v);  // C++17 부터 템플릿 인자 생략 가능합니다.

//	for (int n : v)
//	for (int n : rv)
	for (int n : reverse_view(v) ) // 임시객체를 생성하는 표기법
	{
		std::cout << n << ", ";
	}
}















