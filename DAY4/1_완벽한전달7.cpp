#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() = default;

	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&)      { std::cout << "move" << std::endl; }
};

template<typename T>
void foo(T&& arg)
{
	// 아래 2개 캐스팅의 차이를 정확히 생각해 보세요.
	// 1. foo 의 인자로 lvalue, rvalue 를 보낸것에 따라 다른 캐스팅
	//    lvalue 를 보내면 lvalue 캐스팅
	//    rvalue 를 보내면 rvalue 캐스팅
	// => std::forward()
	Object o1 = static_cast<T&&>(arg);

	// 2. 인자의 value 속성에 상관없이 무조건 rvalue 로 캐스팅
	// => std::move()의 원리
	Object o2 = static_cast<std::remove_reference_t<T>&&>(arg);
}

int main()
{
	Object obj;
	foo(obj);		// lvalue
	foo(Object());	// rvalue
}



