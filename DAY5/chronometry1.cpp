// chronometry1.cpp

class Dialog 
{
public:
	void init(int a, double d) {} 
//  void init(Dialog* this, int a, double d) {} // 컴파일 후!
};

void foo(int a, double d) {}

int main()
{
	void(*f1)(int, double) = &foo;
//	void(*f2)(int, double) = &Dialog::init;

	// 핵심 1. 멤버 함수의 주소를 담을때는 아래처럼 해야 합니다.
	void(Dialog::*f2)(int, double) = &Dialog::init;

	// 핵심 2. 멤버 함수 포인터로 멤버 함수 호출하기
//	f2(1, 3.4);  // error. 객체가 없습니다.

	Dialog dlg;
//	dlg.f2(1, 3.4); // error. f2 는 Dialog 의 멤버 함수가 아닙니다.
	
//	dlg.*f2(1, 3.4); // .* 연산자 사용(pointer to member)
					 // 그런데, 우선 순위 관계로 에러.		
					 // .* 보다 ( 가 우선순위가 높습니다.

	(dlg.*f2)(1, 3.4); // ok. 이 코드가 멤버 함수 포인터로
						// 멤버 함수 호출하는 코드입니다.

	// 정리
	f1(1, 3.4); // 일반 함수 포인터 사용
	(dlg.*f2)(1, 3.4); // 멤버 함수 포인터 사용
}