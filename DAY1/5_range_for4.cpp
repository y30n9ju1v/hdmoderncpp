// 5_range_for4 - 1번 복사해오세요
#include <iostream>
#include <vector>

// 아래 클래스를 잘 생각해 보세요
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

	for (int n : v)
	{
		std::cout << n << ", ";
	}
}















