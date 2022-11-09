// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x;}
// lvalue : 등호의 왼쪽, 오른쪽에 모두 놓일수 있다.
//		    이름이 있고, 문장을 벗어나서도 사용할수 있다.
//		    주소 연산자로 주소를 구할수 있다.
//			참조를 반환하는 함수
// 
// rvalue : 등호의 오른쪽에만 놓일수 있다.
//		    이름이 없고, 단일 문장에서만 사용된다.
//		    주소 연산자로 주소를 구할수 없다.	
//			값을 반환하는 함수
//			literal(5, 3.4 등), 임시객체(temporary)


int main()
{
	int v1 = 10, v2 = 10;

	v1 = 10; // v1 : lvalue,  10 : rvalue

	10 = v1; // error. "10" 은 lvalue 가 될수 없다
	
	v2 = v1; // ok. "v1" 은 rvalue 가 될수 있다.


	int* p1 = &v1; // ok
	int* p2 = &10; // error

	foo() = 10; // error. "0 = 10"
	goo() = 10; // ok     "x = 10"

	//========================
	const int c = 0;
	c = 10;	// error.		c 는 lvalue ? rvalue ?
			// 이름이 있고, 주소도 구할수 있습니다.
			// immutable lvalue 입니다.

	// 모든 rvalue 는 상수 이다 ??? 
	// 1. 예			2. 아니오 => 답

	// 임시객체는 상수는 아닙니다.
	// 단지, 문법상 왼쪽에 올수 없습니다.
	// 임시객체도 메모리를 할당하긴 합니다.
	Point(0, 0).x = 10; // error. 임시객체는 등호의 왼쪽에 올수 없지만
	Point(0, 0).set(10, 20); // 멤버 함수로 변경은 가능합니다.
							 // 즉, 상수는 아닙니다.
}









