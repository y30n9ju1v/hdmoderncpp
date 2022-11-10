// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 핵심 : 아래 함수 인자는 절대 "forwarding reference" 가 아닙니다.
	// 아래 함수는 "함수 템플릿" 이 아닌
	//           "클래스 템플릿"의 "일반 멤버 함수" 입니다.
	// Test<int> t; // 객체 생성시 이미 T 의 타입이 결정
	void foo(T&& arg)
	{
	}

	// forwarding reference 가 되려면 
	// 함수(또는 멤버 함수) 자체가 템플릿 이어야 합니다.
	// => 아래 함수 인자가 forwarding reference 입니다.
	template<typename U>
	void goo(U&& arg)   
	{

	}
};
int main()
{
	int n = 0;
	Test<int> t; // 객체 생성시 이미 T 의 타입이 결정 ( T=int)
				// 따라서, foo 함수는 "foo(int&&)" 로 결정되었습니다.
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);	// error
	t.foo(10);	// ok

	t.goo(n);  // ok
	t.goo(10); // ok
}
