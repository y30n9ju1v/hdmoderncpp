#include <iostream>
#include <vector>
#include <type_traits> // remove_reference_t�� ����
						// C++11 ��� �ε�, remove_reference_t�� C++17
class Object
{
public:
	Object() {}


	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

Object foo()
{
	Object obj;
	return obj;
}

// ���ø� ���鶧 - �Ʒ� �ڵ��� ��� ���ڸ� ������ �� �����ϼ���
// 
// T obj  : ���纻 �����ϰڴٴ°�
// 
// T& obj : lvalue �� �ްڴٴ� ��
// 
// const T& obj : lvalue, rvalue ��� ������, ����� �߰��ϰڴ�

// T&&    : ����� ���� lvalue, rvalue ��� �ްڴ�


template<typename T>
std::remove_reference_t<T>&& xmove(T&& obj)
{
	// �Ʒ� ĳ������ �׻� "rvalue" ĳ���� �� �ƴմϴ�.
	// ��Ȳ�� ���� rvalue �Ǵ� lvalue ĳ�����Դϴ�.
	// 
	// ���ڷ� lvalue �� ���� "lvalue ĳ����"
	// ���ڷ� rvalue �� ���� "rvalue ĳ����" �Դϴ�.
	// return static_cast<T&&>(obj);

	// move �� "move ������" �� ȣ���ϰ� �ؾ� �ϹǷ�
	// => "�׻� rvalue ĳ������ �ؾ� �մϴ�."

	// std::remove_reference_t<T> : T �� ���� ��� ���۷����� ������ Ÿ�Ա��ϱ�
	// T: Object& �϶� �� ����� "Object"
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object o1;
	Object o4 = xmove(o1);		// o1�� lvalue
								// T=Object&	T&&=Object& &&
								// static_cast<T&&>=>static_cast<Object&>

	Object o5 = xmove(foo());	// foo() �� rvalue
								// T=Object		T&&=Object&&
								// static_cast<T&&>=>static_cast<Object&&> 

	Object o6 = std::move(o5); // std::move �� ���콺 �ø���, "���Ƿ��̵�"
}

