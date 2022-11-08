// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자 : 복사 초기화는 사용할수 없고
	//					직접 초기화만 가능하다.!
	//					또한, 변환의 용도로도 사용할수 없다.
	//					C++98 문법
	explicit Vector(int s) : sz(s) {}
};

// 함수의 인자 전달은 복사 초기화 입니다.
void foo(Vector v) {}	// Vector v = 10	
						// Vector v = {10}	
						// Vector v = v1  이므로 복사 생성자
						//		디폴트 복사 생성자는 explicit 아님.
int main()
{
	// 핵심 1. 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);		// C++98. direct initialization
	Vector v2 = 10;		// C++98. copy   initialization

	Vector v3{ 10 };	// C++11. direct initialization
	Vector v4 = { 10 };	// C++11. copy   initialization

	//----------------
	foo(10);		// explicit 인 경우 에러
	foo( { 10 } );	// C++11 부터 이코드도 가능, explicit 인 경우 에러
	foo(v1);  // ok
}







