#include <iostream>
#include <type_traits> 

/*
#pragma pack(1)		// align 을 1바이트 단위로
struct PACKET		// padding 추가하지 않음
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
	memset(p, 0, sizeof(T)); // 안전한 코드 일까요 ?
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