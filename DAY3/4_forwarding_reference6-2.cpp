#include <iostream>
#include <vector>
#include <type_traits> // remove_reference_t를 위해
						// C++11 헤더 인데, remove_reference_t는 C++17
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
std::remove_reference_t<T>&& xmove(T&& obj)
{
	// 아래 캐스팅은 항상 "rvalue" 캐스팅 이 아닙니다.
	// 상황에 따라 rvalue 또는 lvalue 캐스팅입니다.
	// 
	// 인자로 lvalue 가 오면 "lvalue 캐스팅"
	// 인자로 rvalue 가 오면 "rvalue 캐스팅" 입니다.
	// return static_cast<T&&>(obj);

	// move 는 "move 생성자" 를 호출하게 해야 하므로
	// => "항상 rvalue 캐스팅을 해야 합니다."

	// std::remove_reference_t<T> : T 가 가진 모든 레퍼런스를 제거한 타입구하기
	// T: Object& 일때 위 결과는 "Object"
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object o1;
	Object o4 = xmove(o1);		// o1은 lvalue
								// T=Object&	T&&=Object& &&
								// static_cast<T&&>=>static_cast<Object&>

	Object o5 = xmove(foo());	// foo() 는 rvalue
								// T=Object		T&&=Object&&
								// static_cast<T&&>=>static_cast<Object&&> 

	Object o6 = std::move(o5); // std::move 에 마우스 올리고, "정의로이동"
}

