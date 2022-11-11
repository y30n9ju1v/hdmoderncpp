#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("%d, %d, %d\n", a, b, c);
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1,2,3 이 있습니다.

//	goo( args ); // error. pack 을 인자로 직접 사용할수 없습니다.


	// Pack expansion 
	// "팩을 사용하는 패턴"...   => "E1패턴", "E2패턴", "E3패턴"

	goo(args...); // ok. pack 의 모든 요소를 , 를 사용해서
				  //     열거해 달라.
				  // goo(1, 2, 3)

	goo( ++args...); // goo(++E1, ++E2, ++E3)

	// ... 위치가 중요 합니다.
//	goo( hoo(args...) );// goo( hoo(1,2,3)) 인데 hoo의 인자는 한개이므로
						// error

	goo( hoo(args)... );// goo( hoo(E1), hoo(E2), hoo(E3) )
						// goo( hoo(2), hoo(3), hoo(4) )

}




int main()
{
	foo(1, 2, 3);
}
