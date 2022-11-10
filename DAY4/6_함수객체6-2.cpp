#include <iostream>
#include <algorithm>
#include <string>

// C++20 �� ���鶧 ���� ��� �˰����� ���Ӱ� ��������ϴ�.
namespace std
{
	namespace ranges
	{
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
		MaxFn max;

	}
}

int main()
{
	std::string s1 = "a";
	std::string s2 = "n";

	auto ret1 = std::ranges::max(1, 2);	  // ok
	auto ret2 = std::ranges::max(s1, s2); // ok

	using namespace std::ranges;

	auto ret3 = max(1, 2);	 // ok
	auto ret4 = max(s1, s2); // error. ADL ������
							 // std::max �� 
							 // std::ranges::max �� �浹
}
