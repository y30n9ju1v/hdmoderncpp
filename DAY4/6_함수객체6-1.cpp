#include <iostream>
#include <algorithm>
#include <string>

// ����ڰ� C++ ǥ�ذ� ������ �̸��� �Լ��� ������ٰ�
// ������ ���ô�.
/*
template<typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}
*/
struct MaxFn
{
	template<typename T>
	const T& operator()(const T& a, const T& b) const
	{
		return a < b ? b : a;
	}
};

MaxFn max; // max �� �Լ� �� �ƴ� �Լ� ��ü �Դϴ�.

int main()
{
	int ret1 = max(1, 2);	// 1, 2 �� std �ȿ� �ִ� Ÿ�Ծƴմϴ�.							
							// ����ڰ� ���� max ���

	std::string s1 = "a";
	std::string s2 = "n";

	auto ret3 = max(s1, s2); // max �� �Լ� ��� ����(ADL ����)
							// �Լ���ü�� ADL �� �������� �ʽ��ϴ�.
							// ����ڰ� ���� max ���
}
