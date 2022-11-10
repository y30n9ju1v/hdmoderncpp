#include <iostream>
#include <vector>
#include <algorithm>


inline void show1(int n) { std::cout << n << std::endl;}
inline void show2(int n) { std::cout << n << std::endl; }

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
				// => 이 코드는 show1 함수가 10번 호출됩니다.
				// => show1 이 인라인 함수라도 인라인 치환될수 없습니다.
				// => 생성된 함수는 아래 모양인데 마지막 인자가 함수 포인터 입니다.
//  my_for_each( iterator, iterator, void(*)(int))

	my_for_each(v.begin(), v.end(), show2);
//	my_for_each(iterator, iterator, void(*)(int))


	// for_each 에 "일반 함수" 사용시
	// 장점 : 위처럼 "show1" "show2" 를 보내도 생성된
	//	     for_each 는 한개 입니다.
	//		 코드 메모리 감소

	// 단점 : 한개의 for_each 에 2개의 함수 구현을 치환할수는 없습니다.
	//       인라인치환이 안되고, 호출 입니다.
	//	     느립니다.

	my_for_each(v.begin(), v.end(), show1); // for_each(void(*)(int)) 생성
	my_for_each(v.begin(), v.end(), show2); // for_each(void(*)(int)) 생성
}


