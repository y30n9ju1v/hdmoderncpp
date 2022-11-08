class istream
{
public:
	bool fail() { return false; } // 입력실패에 따라 결과반환

	// C++98 : 생성자에만 explicit 를 붙일수 있습니다.
	// C++11 : 변환연산자에도 explicit 를 붙일수 있습니다.
	//         => 암시적 변환은 안되고 명시적 변환만 된다.
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;

int main()
{
	int n = 0;

//	bool b1 = cin; // error 암시적 변환
	bool b2 = static_cast<bool>(cin); // ok. 명시적 변환

//	cin << n;	// error. cin 이 정수(bool)로 암시적 변환이 되면 되는데
				//		  지금은 명시적 변환만 된다.

	if (cin) {}	// if 문 안에서는 자동으로 명시적 변환으로 변환 될수
				// 있다는 C++ 문법에 추가 되었습니다.

	// 결론 : cin 의 변환 이야기
	// C++98 : cin.operator void*() 제공
	// C++11 : cin.operator bool() 제공. 단, explicit

	// 참고. nullptr(std::nullptr_t) 은
	//       bool 로의 명시적 변환을 제공합니다.
//	bool b3 = nullptr; // error
	bool b4 = static_cast<bool>(nullptr); // ok

	if (nullptr) {} // 
}
