// 2_람다표현식1 - 127 page

int add(int a, int b) { return a + b; }


// foo 함수는 인자로 함수 포인터(주소)를 요구합니다

void foo( int(*f)(int, int) )
{
}
int main()
{
	foo(&add); 
	foo(add);  // 함수는 이름만 표기해도 주소로 암시적 변환 됩니다.

	// 람다 표현식
	// => 익명의 함수를 만드는 문법
	// => "클로져" 를 만드는 문법
	// => 함수 주소가 필요한 곳에, 함수 구현 자체를 전달하는 문법

	// [] : lambda introducer, 
	//      람다 표현식이 시작됨을 알리는 것
	foo( [](int a, int b) { return a + b; } );
}

