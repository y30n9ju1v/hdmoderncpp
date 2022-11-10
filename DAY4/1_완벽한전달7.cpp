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
	static_cast<T&&>(arg);
	static_cast<std::remove_reference_t<T>&&>(arg);
}
int main()
{
	Object obj;
	foo(obj);		// lvalue
	foo(Object());	// rvalue
}



