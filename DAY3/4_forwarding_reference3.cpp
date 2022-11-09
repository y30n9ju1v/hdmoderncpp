
// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);  // ok
f1(10); // error

// 함수 인자의 의미
// int&  : int 타입의 lvalue 만 받겠다는 것
// int&& : int 타입의 rvalue 만 받겠다는 것

// T& : 임의 타입의 lvalue 만 받겠다는 것

// T&& : 핵심!!!


template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 0;

	// 1. 사용자가 타입을 명시적으로 전달할때
	f3<int>(n );	// T = int		T& = int&		f3(int& a);
	f3<int&>(n );	// T = int&		T& = int& &		f3(int& a);
	f3<int&&>(n );	// T = int&&	T& = int&& &	f3(int& a);

	f3<int&&>(0);	// error. f3(int& )으로 생성되었는데
					// 해당 함수에 rvalue 를 보내 므로

	// 2. 사용자가 타입을 전달하지 않으면 컴파일러는 
	//    함수 인자를 보고 함수를 생성하기위해 T의 타입을 결정합니다.
	f3(0);	// T 를 int, int&, int&& 중 어떤 것으로 결정해서
			// 0을 받는 함수는 만들수 없습니다.
			// 에러!!

	f3(n);	// T = int 로 결정. 최종 함수는 "f3(int&)"
}


//==============================================



template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 0;

	// 1. 타입을 직접 전달하는 경우. 아래 ? 채워 보세요
	f4<int>(0);		// T=int	T&&=int&&		f4(int&& a)
	f4<int&>(n);	// T=int&	T&&=int&  &&	f4(int&  a)
	f4<int&&>(0);	// T=int&&	T&&=int&& &&	f4(int&& a)


	// 2. 타입인자를 생략하는 경우

	f4(n);	// 1. n 은 int 타입이다. T=int 로 결정하자!!
			// => 생성된 함수는 f4(int&& a) 이므로 "f4(n)" 은 에러!!
				  
			// 2. n 은 int 타입이지만, T=int& 로 결정하면 
			// => f4(int&) 가 되므로 "f4(n)" 은 에러가 아니다.
			// => T=int& 로 결정하자!! => 정답!!!!

	f4(0);	// T=int 또는 int&& 로 결정하면 되는데.
			// 표준에서는 "T=int"로 결정
			// 생성된 함수는 "f4(int&&)"
}

// T&& : 임의 타입의 lvalue 와 rvalue 를 모두 받을수 있다.
//       "받을수 있다" 는 "받을수 있는 함수를 생성할수 있다" 의 의미
// 
// 특징 : 생성된 함수는 모두 "call by reference" 입니다.!!

// 즉, 모든 객체를 복사본 없이 받겠다는 것!!

// 아래 주석 반드시 외우세요..!!
// 함수 인자로 
// lvalue(n) 을 보내면 : T=int&    T&&=int& &&  최종함수 f4(int&)
// rvalue(0) 을 보내면 : T=int     T&&=int&&    최종함수 f4(int&&)

// 이름
// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference

// T&&   : rvalue reference 가 아닙니다.
//         "forwarding reference" 가 공식 명칭
//		   "universal reference" 라고도 합니다.(effective-C++)


