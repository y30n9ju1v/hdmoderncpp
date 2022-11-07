// 5_range_for4 - 1�� �����ؿ�����
#include <iostream>
#include <vector>

// �Ʒ� Ŭ������ �� ������ ������
// => C++20 ���� �����ϴ� "�ð�(View)" �Դϴ�.
// => C++20 "Range" ���̺귯���� ����
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

	reverse_view rv(v);  // C++17 ���� ���ø� ���� ���� �����մϴ�.

//	for (int n : v)
//	for (int n : rv)
	for (int n : reverse_view(v) ) // �ӽð�ü�� �����ϴ� ǥ���
	{
		std::cout << n << ", ";
	}
}















