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
	// std::is_polymorphic<T>::value : T 안에 가상함수가 있으면 true!

	static_assert(!std::is_polymorphic<T>::value,
					"error, T has virtual function");

	memset(p, 0, sizeof(T)); // 안전한 코드 일까요 ?
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

// 결국 "static_assert" 는
// => 기능, 성능의 도구가 아니라!
// => 안전한 코드를 작성하기 위한 도구 입니다.
// => STL 내부나, 오픈소스에서 아주 널리 사용됩니다.
// => 교재 9page 예제 몇개 더 있습니다.