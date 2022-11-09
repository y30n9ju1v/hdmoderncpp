#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}


	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

Object foo()
{
	Object obj;
	return obj;
}

// C++표준 함수는 "std::move()" 를 구현해 봅시다.
template<typename T>
T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}



int main()
{
	Object o1;
	Object o2 = o1;			// copy
	Object o3 = foo();		// move
	Object o4 = xmove(o1);	// move
	Object o5 = xmove(foo());	// xmove() 를 사용하지 않아도 move 지만!
								// 즉, xmove() 가 없어도 되지만
								// 이 코드도 에러는 없어야 합니다.
	
}

