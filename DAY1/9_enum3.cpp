#include <iostream>
#include <type_traits>

// ���ο� enum �� ���������� ����ϴ� Ÿ���� �����Ҽ� �ֽ��ϴ�.

//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	// DAYOFWEEK enum �� ���������� ����ϴ� Ÿ��
	std::cout << typeid(std::underlying_type_t<DAYOFWEEK>).name()
			  << std::endl;
}




