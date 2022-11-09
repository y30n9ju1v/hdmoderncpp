#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Object
{
	int id;
	std::string name;
	T data;

public:
	Object() {}


	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}
	// move 생성자에서는 모든 멤버를 "std::move()" 로 옮겨라!
	// 아래 코드에서 "noexcept" 를 어떻게 해야 할까요 ?

	// void f1() noexcept       : 예외가 없다.
	// void f1() noexcept(true) : 예외가 없다.
	// void f1() noexcept(false): 예외가 있다.

	// string : move 생성자에 예외 없습니다.(cppreference.com 참고)
	// T      : 알수 없습니다. 아래 처럼 조사해야 합니다.
	Object(Object&& other) 
		noexcept ( std::is_nothrow_move_constructible<T>::value  )
		: id(other.id), 
		  name(std::move(other.name)),
		  data(std::move(other.data))
	{
		std::cout << "move" << std::endl;
	}
};


int main()
{
	Object o1;
	Object o2 = o1; 
	Object o3 = std::move(o1); 
	Object o4 = std::move_if_noexcept(o2);

	// 반드시 "noexcept" 이어야 하는 것들
	// => noexcept를 안 붙여도 noexcept 입니다.
	// 1. 소멸자
	// 2. operator delete() 함수

	// 되도록 "noexcept" 로 하라고 강력! 권장하는 것
	// 1. move 생성자, move 대입 연산자
	// 2. swap() 함수

	// "noexcept" 를 붙이면 좋은 함수
	// 1. 생성자(특히 default 생성자)

	std::pair<int, double> p1;
				// 디폴트 생성자에 noexcept 를 붙일수 있는지 여부는
				// T1, T2 타입의 디폴트 생성자에 예외 여부에 달려 있습니다.
			
}

