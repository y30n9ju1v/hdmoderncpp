// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Test::data  * p;	// 0 * 0.  즉, * 는 곱하기 연산자(이항연산자) 
//	Test::DWORD * p;	// int* p  즉, * 는 포인터 변수 선언

	// 핵심 1. "클래스 이름::이름" 으로 표기할때 "이름"의 의미는
	// "값"  또는			   : enum 상수, static 멤버 등
	// "타입" 일수 있습니다.  : typedef, using 등

	// dependent name(의존이름)
	// => 템플릿 인자 T에 의존해서 꺼내는 이름
	// => 컴파일러는 항상 "값"으로 해석 합니다.

	T::data * p;		// ok
//	T::DWORD * p2;		// error

	typename T::DWORD* p2; // ok

	// 핵심 2. dependent name 이 type 인 경우는 
	//		반드시 앞에 "typename" 을 붙여야 합니다.
	// => C++98 시절 문법
}



int main()
{
	Test t;
	foo(t);
}



