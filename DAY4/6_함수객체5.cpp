#include <iostream>
#include <vector>
#include <algorithm>

void show1(int n)
{
	std::cout << n << std::endl;
}

// STL 의 for_each 를 직접 만들어 봅시다.
template<typename T, typename F>
void my_for_each(T first, T last, F f)
{
	while (first != last)
	{
		f(*first);
		++first;
	}
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	my_for_each(v.begin(), v.end(), show1);

}

