
// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);  // ok
f1(10); // error

// 함수 인자의 의미
// int&  : int 타입의 lvalue 만 받겠다는 것
// int&& : int 타입의 rvalue 만 받겠다는 것

// T& : ?


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 0;

	// 1. 사용자가 타입을 명시적으로 전달할때
	f3<int>(? );	// T = ?	a = ?		f3(? a);
	f3<int&>(? );	// T = ?	a = ?		f3(? a);
	f3<int&&>(? );	// T = ?	a = ?		f3(? a);


}











template<typename T> void f4(T&& a)
{
}
