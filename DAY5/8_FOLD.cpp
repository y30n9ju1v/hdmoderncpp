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
//	int s = (...  + args); // ((1 + 2) + 3) ) => unary left fold
		  

//	int s = (args + ... + 0); // (1+(2+(3+0))) => binary right fold
	int s = (0 + ... + args); // (((0+1)+2)+3) => binary left fold

	// �ٽ� : fold expression �� ��ó�� 4���� ǥ����� �ֽ��ϴ�
	
	return s;
}
int main()
{
//	int n = Sum(1, 2, 3);
	int n = Sum(); 

	std::cout << n << std::endl;
}



