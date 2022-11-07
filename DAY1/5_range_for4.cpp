// 5_range_for4 - 1�� �����ؿ�����
#include <iostream>
#include <vector>

// �Ʒ� Ŭ������ �� ������ ������
template<typename T>
class reverse_view
{
	T& range;
public:
	reverse_view(T& r) : range(r) {}

	auto begin() { return range.rbegin(); } // �ٽ�!!!
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















