// 16_constexpr4
#include <iostream>
#include <type_traits>

constexpr std::pair<int, bool> add(int a, int b)
{
	bool ret = std::is_constant_evaluated(); // C++20

	return std::pair<int, bool>(a + b, ret);
}

int main()
{
	auto ret = add(1, 2);

	std::cout << ret.second << std::endl;
}