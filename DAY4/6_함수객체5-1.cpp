#include <iostream>
#include <vector>
#include <algorithm>



struct show_function_object
{
	inline void operator()(int n) const
	{
		std::cout << n << std::endl;
	}
};

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
	
	show_function_object  sfo;
	show_function_object2 sfo2;

	my_for_each(v.begin(), v.end(), sfo ); // for_each(show_function_object  );
	my_for_each(v.begin(), v.end(), sfo2); // for_each(show_function_object2  );

	// 함수가 아닌 함수 객체를 사용하면
	// 위처럼 다른 타입의 함수객체를 보내면

	// 단점 : 여러개의 for_each 함수가 생성된다. 코드 메모리 증가
	// 장점 : operator() 가 인라인 치환 됩니다. 속도가 빨라 집니다.
	
}

