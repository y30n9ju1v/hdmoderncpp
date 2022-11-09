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

// 템플릿 만들때 - 아래 코드중 어떻게 인자를 받을지 잘 선택하세요
// 
// T obj  : 복사본 생성하겠다는것
// 
// T& obj : lvalue 만 받겠다는 것
// 
// const T& obj : lvalue, rvalue 모두 받지만, 상수성 추가하겠다

// T&&    : 상수성 없이 lvalue, rvalue 모두 받겠다


template<typename T>
T&& xmove(T&& obj)
{
	return static_cast<T&&>(obj);
}



int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = foo();			// move
	Object o4 = xmove(o1);		// move
	Object o5 = xmove(foo());	// move


}

