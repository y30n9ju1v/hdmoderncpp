#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() = default;

	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&)      { std::cout << "move" << std::endl; }
};

template<typename T>
void foo(T&& arg)
{
	// �Ʒ� 2�� ĳ������ ���̸� ��Ȯ�� ������ ������.
	static_cast<T&&>(arg);
	static_cast<std::remove_reference_t<T>&&>(arg);
}
int main()
{
	Object obj;
	foo(obj);		// lvalue
	foo(Object());	// rvalue
}



