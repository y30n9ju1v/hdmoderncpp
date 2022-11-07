// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0; // 0 은 포인터가 아닌 "int" 타입입니다.
				 // 하지만, "0"은 포인터로 암시적 형변환가능합니다.

	// C++11 이후에는 포인터 초기화시 "0" 대신 "nullptr" 사용하세요
	int* p2 = 0; // bad
	int* p3 = nullptr; // ok

	// 장점 1. 가독성이 좋다.
	auto p4 = foo();

	if (p4 == 0) {}       // p4의 타입이 정수인지 포인터 인지 알수 없다
	if (p4 == nullptr) {} // p4의 타입이 포인터 임을 알수 있다.
}