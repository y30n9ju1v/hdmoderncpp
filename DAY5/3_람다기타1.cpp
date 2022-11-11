class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const 
	{ 
		return a + b; 
	}

	// 함수 포인터로의 변환을 지원하기 위해
	// operator() 와 구현이 동일한 static 멤버 함수도 컴파일러가 생성
	static inline int helper(int a, int b) 
	{
		return a + b;
	}

	// 함수포인터로의 변환을 위한 변환 연산자
	using FP = int(*)(int, int);

//	operator FP() { return &CompilerGeneratedName::operator(); }
				// => error 입니다.
				// => 일반 함수 포인터는 "멤버 함수 주소"와 호환 안됩니다.
				// => static 멤버 함수로 해야 합니다.

	operator FP() { return &CompilerGeneratedName::helper; }
};


int main()
{
	int(*f2)(int, int) = CompilerGeneratedName();
						// 임시객체.operator 함수포인터();


	// 람다 표현식은 "함수 포인터"로 변환 가능합니다.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx();
			
}












