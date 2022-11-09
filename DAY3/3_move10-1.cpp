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

}

