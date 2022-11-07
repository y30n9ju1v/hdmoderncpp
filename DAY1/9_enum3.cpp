#include <iostream>
#include <type_traits>

enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	std::cout << typeid(std::underlying_type_t<DAYOFWEEK>).name()
			  << std::endl;
}




