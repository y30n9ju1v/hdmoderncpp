
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
	f4<int>(? );	// T=?		T&&=?			f4(? a)
	f4<int&>(? );	// T=?		T&&=?			f4(? a)
	f4<int&&>(? );	// T=?		T&&=?			f4(? a)

	// 2. 타입인자를 생략하는 경우

	f4(n);
	f4(0);
}