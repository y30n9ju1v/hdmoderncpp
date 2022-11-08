// 3_�ʱ�ȭ4-4
// C++20 ���� ���ο� explicit ������ ���ɴϴ�
#include <iostream>
#include <type_traits>

template<typename T>
class Opt
{
	T value;
public:
	// explicit(true) ������;
	// explicit(false) ������;
	explicit(std::is_integral<T>::value) 
	Opt(T n) : value(n) {}
};

int main()
{
	Opt p1(10);
	Opt p2 = 10; // error. explicit 

	Opt p3(3.4);
	Opt p4 = 3.4; // ok.. ������ �ƴϹǷ� explicit�ƴ�.
}