// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);

	// tuple : ���� �ٸ� Ÿ�� N���� ���� - C++11
	std::tuple<int, double, char, short> t(1, 3.4, 'A', 3);

}