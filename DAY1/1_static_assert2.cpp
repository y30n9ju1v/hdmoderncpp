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
	memset(p, 0, sizeof(T)); // ������ �ڵ� �ϱ�� ?
}

class Object
{
	int data;
public:
	virtual void foo() {}
};

int main()
{
	Object obj;
	object_set_zero(&obj);
}