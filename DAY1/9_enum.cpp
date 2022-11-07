// 9_enum - 32 page

enum DAYOFWEEK { sum = 0, mon = 1};

// 함수 인자로 요일을 받고 싶다.
void foo(int dayofaweek) {}

int main()
{
	foo(0); // 0 : 일요일, 1 : 월요일 .... 
			// => 가독성이 좋지 않다.

	foo(DAYOFWEEK::mon); // 이렇게 해도 되고
	foo(mon);	// 이렇게 해도 됩니다.
				// "unscoped enum" 
				// 이름 충돌의 가능성이 있다. 
				// 보다 안전한 새로운 enum 을 만들자!
	int mon = 100;
	foo(mon);	// ???? 에러 ? enum ? 지역변수 ?
				// => 지역변수 사용
}





