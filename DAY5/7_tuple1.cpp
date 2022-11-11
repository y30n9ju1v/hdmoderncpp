// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	// tuple : 서로 다른 타입 N개를 보관 - C++11
	std::tuple<int, double, char, short> t(1, 3.4, 'A', 3);

}