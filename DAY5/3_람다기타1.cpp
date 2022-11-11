class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const 
	{ 
		return a + b; 
	}

	// 함수포인터로의 변환을 위한 변환 연산자
	using FP = int(*)(int, int);

	operator FP() { return 함수 주소; }
};


int main()
{
	int(*f2)(int, int) = CompilerGeneratedName();
						// 임시객체.operator 함수포인터();


	// 람다 표현식은 "함수 포인터"로 변환 가능합니다.
	int(*f1)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx();
			
}












