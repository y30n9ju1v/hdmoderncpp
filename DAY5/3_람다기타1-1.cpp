class CompilerGeneratedName
{
	int v1;
public:
	CompilerGeneratedName(int a) : v1(a) {}

	inline int operator()(int a, int b) const
	{
		return a + b + v1; // ok~~~~
	}

	// 지역변수를 캡쳐한 람다 표현식은
	// 함수 포인터로의 변환을 위한 아래 함수를 만들수 없습니다!!
	// => 그래서 함수 포인터로 변환 될수 없습니다.
	/*
	static inline int helper(int a, int b)
	{
		return a + b + v1; // error.
						// static 멤버 함수는 멤버데이타 접근 안됨.
	}

	using FP = int(*)(int, int);
	operator FP() { return &CompilerGeneratedName::helper; }
	*/
};


int main()
{
	int v1 = 0;
	// 지역변수를 캡쳐한 람다 표현식과 함수 포인터!
	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };
//	int(*f2)(int, int) = CompilerGeneratedName(v1);

}












