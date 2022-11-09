#include <iostream>
#include <vector>

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
T&& xmove(T&& obj)
{
	return static_cast<T&&>(obj);
}



int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = foo();			// move
	Object o4 = xmove(o1);		// move
	Object o5 = xmove(foo());	// move


}

