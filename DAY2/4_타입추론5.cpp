// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);
	// T a = 10; // 결국 이 표기법 입니다. 10 으로 T의 타입 추론
	auto a = 10; // T 자리에 auto 가 있는 것 입니다.
				 // 규칙은 동일 합니다.



	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// T a1 = n; 입니다. 즉, "규칙 1"입니다.
	//			=> 우변 표현식이 가진 const, volatile, reference 제거
	//			   후 auto 결정
	auto a1 = n;  // int a1
	auto a2 = r;  // int a2 
	auto a3 = c;  // int a3
	auto a4 = cr; // int a4

	// T& a5 = n;  // 규칙 2. 우변이 가진 reference 만 제거후 auto 타입결정
	auto& a5 = n;  // auto : int		a5 : int&
	auto& a6 = r;  // auto : int		a6 : int&
	auto& a7 = c;  // auto : const int  a7 : const int&
	auto& a8 = cr; // auto : const int  a8 : const int&

	// 규칙 3. forwarding reference
	auto&& a9 = 10; // 중요! 별도로 설명
}


