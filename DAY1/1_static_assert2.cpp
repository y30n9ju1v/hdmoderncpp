#include <iostream>
#include <type_traits> 

/*
#pragma pack(1)		// align �� 1����Ʈ ������
struct PACKET		// padding �߰����� ����
{
	char cmd;
	int  data;
};
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			"error. unexpected padding");

int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/



template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic<T>::value : T �ȿ� �����Լ��� ������ true!

	static_assert(!std::is_polymorphic<T>::value,
					"error, T has virtual function");

	memset(p, 0, sizeof(T)); // ������ �ڵ� �ϱ�� ?
}
class Object
{
	int data;
public:
//	virtual void foo() {}
};

int main()
{
	Object obj;
	object_set_zero(&obj);
}

// �ᱹ "static_assert" ��
// => ���, ������ ������ �ƴ϶�!
// => ������ �ڵ带 �ۼ��ϱ� ���� ���� �Դϴ�.
// => STL ���γ�, ���¼ҽ����� ���� �θ� ���˴ϴ�.
// => ���� 9page ���� � �� �ֽ��ϴ�.