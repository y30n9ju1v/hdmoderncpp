// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::for_each(v.begin(), v.end(),
		[](int n) { std::cout << n << std::endl; });

	// ����ǥ������ ����.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int n) const
		{
			std::cout << n << std::endl;
		}
	};

	std::for_each(v.begin(), v.end(), CompilerGeneratedName() );

}





