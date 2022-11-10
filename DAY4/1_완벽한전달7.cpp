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
	// 1. foo �� ���ڷ� lvalue, rvalue �� �����Ϳ� ���� �ٸ� ĳ����
	//    lvalue �� ������ lvalue ĳ����
	//    rvalue �� ������ rvalue ĳ����
	// => std::forward()
	Object o1 = static_cast<T&&>(arg);

	// 2. ������ value �Ӽ��� ������� ������ rvalue �� ĳ����
	// => std::move()�� ����
	Object o2 = static_cast<std::remove_reference_t<T>&&>(arg);
}

int main()
{
	Object obj;
	foo(obj);		// lvalue
	foo(Object());	// rvalue
}



