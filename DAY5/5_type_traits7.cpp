// 4_type_traits - 184page

#include <iostream>
#include <type_traits>

template<typename T> void printv(const T& v)
{
	// if          : ����ð� ���ǹ�
	// if consexpr : �����Ͻð� ���ǹ�
	//				 ������ false ���. 
	//				 ���ø����� ���� C++ �Լ��� �����Ҷ� ���� �ȵ�.!
//	if ( std::is_pointer_v<T> )

	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}


