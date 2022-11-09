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
	// move 계열 함수 만들때 적극 권장!!!

	// 1. 예외가 발생하지 않도록 만드세요
	//    대부분 포인터 얕은 복사이므로 예외가 거의 없습니다.
	// 2. 예외가 없음을 컴파일러에게 알리기 위해서 noexcept 를 꼭 붙이세요
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자 호출
	Object o3 = std::move(o1); // 항상 move 생성자 호출
	Object o4 = std::move_if_noexcept(o2);
					// => move 생성자에 예외가 없다면 move 생성자
					//                      있다면 복사 생성자 사용

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10);	// 이순간의 원리를 생각해봅시다.
					// 작은 버퍼의 요소를 큰 버퍼로 옮길때
					// "std::move_if_noexcept" 사용합니다.

	std::cout << "----------------" << std::endl;
}

