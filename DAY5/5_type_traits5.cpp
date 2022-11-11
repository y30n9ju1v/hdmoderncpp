#include <iostream>
#include <type_traits>

int main()
{
	std::remove_pointer<int***>::type n1;
					// => n1 은 int** 입니다.
					// => 즉, 포인터 한개 만 제거 됩니다.

	remove_all_pointer<int***>::type n;	
					// => n이 int 되게 도전해 보세요
					//    어렵습니다.
}
