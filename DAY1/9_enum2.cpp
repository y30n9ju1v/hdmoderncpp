// enum2.cpp 를 아래 코드로 변경하세요

//enum     DAYOFWEEK { sum = 0, mon = 1 };	// C++98 unscoped enum
enum class DAYOFWEEK { sum = 0, mon = 1 };	// C++11 scoped enum

//void foo(int dayofaweek) {}	// 요일뿐 아니라 100,200등
								// 잘못된 값이 될수 있다.

void foo(DAYOFWEEK dayofweek) {}// 요일만 받을수 있다.

int main()
{
//	int n1 = mon;			// error.  
							// "DAYOFWEEK::mon" 로 사용해야 합니다.
//	int n2 = DAYOFWEEK::mon;// error. 
							// int 타입이 아니라 "DAYOFWEEK" 타입

	DAYOFWEEK n3 = DAYOFWEEK::mon; // ok. 

	foo(DAYOFWEEK::mon);
}





