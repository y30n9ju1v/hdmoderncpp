
void true_function() {} // 주소만 사용하려고 만든 함수입니다.

// std::cin 은 istream 클래스의 객체 입니다.
// (정확히는 basic_istream)
class istream
{
	struct dummy
	{
		void true_function() {}
	};
public:
	bool fail() { return false; } // 입력실패에 따라 결과반환

	// 방법 1. operator bool() 변환 연산자를 제공하자
	// 단점 : "cin << n" 의 코드가 에러가 없다!!
	// operator bool() { return fail() ? false : true; }

	// 방법 2. void* 로의 변환
	// => this 를 반환하는 것은 특별한 이유 없습니다. 그냥 0이 아니면됩니다.
	// => C++98 표준. cin 은 void* 로의 변환 가능합니다.
	// => 단점 : delete cin 이 에러가 아니다. 
	// operator void* () { return fail() ? 0 : this; }

	// 방법 3. 함수 포인터로의 변환 
	// => "delete 함수 포인터" 는 컴파일 에러이다.
//	typedef void(*PF)();
//	operator PF() { return fail() ? 0 : &true_function; }

	// 방법 4. 멤버 함수 포인터로의 변환
	// => boost 라이브러리가 사용하는 방식
	// => C++ 기술문서에서 "safe bool" 이라는 용어로 알려진 기술
	typedef void(dummy::*PF)(); // 멤버 함수 포인터 타입!

	operator PF() { return fail() ? 0 : &dummy::true_function; }
};
istream cin;

int main()
{
	int n = 0;

	if (cin) {}
//	cin << n;   // ?? 잘 보세요.. 잘못된 코드입니다. << 아니라 >> 입니다.
//	delete cin; // boost 라이브러리 팀이 제시한 C++98 표준의 문제점

//	void(*p)() = cin; // 이것도 안되게 하는게 좋지 않을까 ?
}
