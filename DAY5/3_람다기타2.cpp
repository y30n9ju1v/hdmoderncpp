// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분


// 방법 1. 함수 포인터 사용
// 단점 1. 지역변수를 캡쳐한 람다 표현식은 받을수 없다.
//     2. f(1,2) 코드가 인라인 치환될수 없다.
//void foo(int(*f)(int, int))
//{
//	int ret = f(1, 2);
//}

// 방법 2. 모든 람다 표현식은 결국 다른 타입이다.
//        템플릿 사용 - call by value
// 캡쳐하지 않은 람다 표현식은 "empty class" 이다. sizeof(empty)는 1바이트
// 생성자, 복사 생성자도 하는일이 없다.
// "call by value" 도 나쁘지 않다
// std::find_if( first, last, T f) 로 되어 있다.
/*
template<typename T> void foo(T f)
{
	auto ret = f(1, 2);
}
*/
// 방법 3. call by reference
// => 람다표현식은 "임시객체" 입니다.
// => rvalue 이므로 아래 함수는 람다표현식을 받을수 없습니다.
/*
template<typename T> void foo(T& f)
{
	auto ret = f(1, 2);
}
*/
// 방법 4. call by const reference 
// => "operator()" 가 반드시 상수 멤버 함수 이어야만 사용가능합니다
// => mutable 람다를 사용할수 없습니다.
/*
template<typename T> void foo(const T& f)
{
	auto ret = f(1, 2);
}
*/
// 방법 5. forwarding reference
// => 좋은 방법.. 오픈소스에서 많이 볼수 있습니다.
// => 람다표현식 뿐 아니라, 크기가 큰(멤버데이타가 많은) 함수 객체인 경우
//    call by value 보다 좋습니다
template<typename T> void foo(T&& f)
{
	auto ret = f(1, 2);
}


int main()
{
	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) { return a - b; });
}


