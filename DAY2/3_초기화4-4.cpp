// 3_초기화4-4
// C++20 에서 새로운 explicit 문법이 나옵니다
#include <iostream>
#include <type_traits>

template<typename T>
class Opt
{
	T value;
public:
	// explicit(true) 생성자;
	// explicit(false) 생성자;
	explicit(std::is_integral<T>::value) 
	Opt(T n) : value(n) {}
};

int main()
{
	Opt p1(10);
	Opt p2 = 10; // error. explicit 

	Opt p3(3.4);
	Opt p4 = 3.4; // ok.. 정수가 아니므로 explicit아님.
}