// 91 page
int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ok. 포인터를 가리키는 포인터를 만들수
					//     있습니다. ( 이중 포인터 )

	int& r = n;
//	int& &rr = r;	// error. reference 를 가리키는 reference
					//		를 직접 코딩으로 만들수 없습니다.

	// 타입 추론 과정에서 발생되는 reference 충돌은 에러가 아닙니다.
	// "reference collapsing" 이라는 규칙이 적용됩니다.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n;	// int&  &		=> int&
	RREF& r4 = n;	// int&& &		=> int&
	LREF&& r5 = n;	// int&  &&		=> int&
	RREF&& r6 = 10;	// int&& &&		=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// 아래 처럼 사용했다면  r의 타입은 ?
				// "int& & r = a"
				// "int& r = a"
}

foo<int&>(n); 




