// 5_�ӽð�ü3-1
#include <iostream>
#include <string>

// max �� ����� ���ô�.
// 1. ���纻����, �ӽð�ü�� �������� "const &"
// 2. ��ȯ ���� ���纻�������� const &
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
	// ret1�� �ᱹ s2�� ����ŵ�ϴ�.
	// �׻� ���� �մϴ�.

	const std::string& ret2 = max(std::string("aaa"),
								  std::string("bbb"));
	// ret2�� �����ұ�� ?
	// ret2 �� "dangling reference" �Դϴ�. ����ϸ� �ȵ˴ϴ�.
	// �ӽð�ü�� �������� "������ ����" �ѹ��� �����մϴ�.

	// cppreference.com ���� "std::max" �˻��� ������.
	// "Notes" �о� ������.
}
