// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// move 생성자 호출


	// 핵심 : 상수 객체는 move 될수 없습니다.
	const Object o3;  // 핵심. 
	Object o4 = std::move(o3);	// 복사 생성자 호출
				// static_cast<o3타입&&>(o3) 인데, o3타입이 "const Object" 
				// static_cast<const Object&&>(o3)
}





