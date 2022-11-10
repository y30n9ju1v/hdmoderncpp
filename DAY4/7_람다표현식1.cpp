// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// STL 알고리즘에 함수를 전달 할때 

//	std::for_each(v.begin(), v.end(), "일반단항함수");
//	std::for_each(v.begin(), v.end(), "일반단항함수객체");


	// C++11 부터는 함수나 함수객체 대신 람다표현식 가능
	std::for_each(v.begin(), v.end(), 
					[](int n) { std::cout << n << std::endl; });
}





