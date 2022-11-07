
class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

// 34 page 참고
// operator"" 함수의 인자타입은 약속되어 있습니다.

// 사용자가 만드는 것 : "_"로 시작해야 합니다.
//					 "_" 로 시작하지 않는 것은 C++ 표준에서 예약되어 
//					있습니다.

Meter operator""_m(unsigned long long n)
{
	Meter m( static_cast<int>(n) );
	return m;
}

int main()
{
	double d = 3.4; // "3.4" 는 double 타입 입니다.
	float f = 3.4f; // "3.4f" 는 float 타입 입니다.

	Meter me = 3_m;	// operator""_m(3) 을 찾게 됩니다.

//	Gram  g = 3g;
}




