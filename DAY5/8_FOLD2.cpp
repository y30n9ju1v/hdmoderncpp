#include <iostream>
#include <vector>
template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// 핵심 1. 초기값이 "0" 뿐 아니라 "std::cout" 이 될수도 있습니다.
	// (std::cout << ... << args);
	// (((std::cout << 1 ) << 2 ) << 3)


	// 핵심 2. + 뿐 아니라 많은 이항 연산을 활용하세요!!
	//        "<<", "," 등
	// pack 이름 위치에는 이름 뿐 아니라 pack 을 사용하는 패턴도 가능
	(printv(args), ...);
	// ( printv(1), ( printv(2), ( printv(3), printv(4) )))
}

template<typename C, typename ... Types>
void insert_container(C& c, Types...args)
{
	(c.push_back(args), ...);
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	std::vector<int> v;
	insert_container(v, 1, 2, 3, 4, 5, 6);
}



