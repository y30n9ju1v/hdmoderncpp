// 9_FOLD - 237 page
#include <iostream>

// fold expression : C++17
// => parameter pack �� ��� ��ҿ� ���� ���� ������ ����
// => �ݵ�� () �� ǥ���ؾ� �մϴ�.


template<typename ... Types> 
int Sum(Types ... args)
{
	// ( pack�̸�  ���׿����� ...)
//	int s = (args + ... ); // (1 + ( 2 + 3) ) => unary right fold
	int s = (...  + args); // ((1 + 2) + 3) ) => unary left fold
		  

	return s;
}
int main()
{
	int n = Sum(1, 2, 3);

	std::cout << n << std::endl;
}



