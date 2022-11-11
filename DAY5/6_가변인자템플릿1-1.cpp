// 6_가변인자템플릿1 - 1

// "인자가 한개인 함수를 생성"하는 템플릿
template<typename T> void foo(T arg)
{
}

// 가변 인자 함수 템플릿
// => ... 위치 잘 알아 두세요.
// => 인자의 갯수가 N 개인 함수를 생성할수 있는 템플릿
// => godbolt.org 에서 확인해 보세요..( 이 사이트 잘 활용하세요 )
template<typename ... Types> void goo(Types ... args)
{
}

int main()
{
	foo(1);		// foo(int)		생성
	foo(3.4);	// foo(double)  생성

	goo(1);		// goo(int) 생성
	goo(3.4);	// goo(double) 생성
		
	goo(1, 3.4, "aaa"); // goo(int, double, const char*) 생성
						// Types : int, double, const char*
						// args  : 1,   3.4,    "aaa"
}


