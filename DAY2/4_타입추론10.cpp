// 후위반환 - 73 page 아래 부분
#include <iostream>

/*
// 아래 코드에서 반환 타입을 어떻게 표기해야 할까 ?
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// 방법 1. auto 사용
// => return "표현식" 을 보고 타입을 결정해 달라는 의미. 
// 특징 1 : return 문장이 여러개 있다면 추론 할수 없다.
// 특징 2 : return "표현식" 의 결과가 참조 타입인 경우에도
//         auto 는 참조를 버리고 결정하므로 "값" 타입으로 반환
/*
template<typename T1, typename T2>
auto Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// 방법 2. decltype(auto) 반환
// 특징 1. return 문이 여러개 있으면 추론될수 없다.
// 특징 2. return "표현식" 의 결과를 그대로 반환 타입으로 사용
//        표현식의 결과가 참조 라면 참조 반환
/*
template<typename T1, typename T2>
decltype(auto) Mul(T1 a, T2 b)
{
	return a * b;
}
*/
// 방법 3. 반환 타입을 직접 표기
// => return 문이 여러개 라도 에러내지 말라는 의도
// => 그런데, 아래 코드는 a, b를 선언전에 사용하고 있으므로 컴파일 에러
/*
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// 방법 4. C++11에서 추가된 "후위 반환 타입 표기법" 사용
// => auto add(int a, int b) -> int {return a + b;}

// 특징 : return 문이 여러개 있어도 컴파일러는 "decltype(a* b)" 로 
//       타입 추론
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}



int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

