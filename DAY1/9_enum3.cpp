#include <iostream>
#include <type_traits>

// 새로운 enum 은 내부적으로 사용하는 타입을 변경할수 있습니다.

//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	// DAYOFWEEK enum 이 내부적으로 사용하는 타입
	std::cout << typeid(std::underlying_type_t<DAYOFWEEK>).name()
			  << std::endl;
}




