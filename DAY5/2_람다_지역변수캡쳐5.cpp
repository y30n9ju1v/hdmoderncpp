// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
		// auto f = [](int a) { return a + data; }; // error

		//auto f = [data](int a) { return a + data; }; // error
										// data 는 지역변수는 아님

		// 멤버 데이타에 접근 하려면 this를 캡쳐해야 합니다.
		auto f = [this](int a) { return a + data; }; // ok


		// 아래 코드는 "멤버 data" 를 수정할까요 ? 복사본을 수정할까요 ?
		// => 객체의 복사본이 아닌 주소의 복사본이므로
		// => "data=a" 는 원본 멤버 데이타의 수정입니다.
		auto f2 = [this](int a) { data = a; };

		f2(33);
		std::cout << data << std::endl; // ?

		// 아래 코드가 주소가 아닌 객체의 복사본을 캡쳐
		// => C++17 부터 지원
		auto f3 = [*this](int a) mutable { data = a; };
	}
};

int main()
{
	Test t;
	t.foo(); 
}


