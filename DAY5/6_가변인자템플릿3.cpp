#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) 
{
	printf("%d, %d, %d\n", a, b, c);
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1,2,3 �� �ֽ��ϴ�.

//	goo( args ); // error. pack �� ���ڷ� ���� ����Ҽ� �����ϴ�.


	// Pack expansion 
	// "���� ����ϴ� ����"...   => "E1����", "E2����", "E3����"

	goo(args...); // ok. pack �� ��� ��Ҹ� , �� ����ؼ�
				  //     ������ �޶�.
				  // goo(1, 2, 3)

	goo( ++args...); // goo(++E1, ++E2, ++E3)

	// ... ��ġ�� �߿� �մϴ�.
//	goo( hoo(args...) );// goo( hoo(1,2,3)) �ε� hoo�� ���ڴ� �Ѱ��̹Ƿ�
						// error

	goo( hoo(args)... );// goo( hoo(E1), hoo(E2), hoo(E3) )
						// goo( hoo(2), hoo(3), hoo(4) )

}




int main()
{
	foo(1, 2, 3);
}
