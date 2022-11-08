// 20_타입추론1 - 69 page
// 타입 추론 문법

int main()
{
	int x[3] = { 1,2,3 };

	auto n = x[0]; // "int n = x[0]"


	const int c = 10;

	auto a = c; // 1. const int a = c;
				// 2. int a = c; // => 답.. 

	// type deduction(type inference 라고도 합니다.)
	// => 타입 추론, 타입 연역
	// => 표현식을 보고 컴파일러가 타입을 추론하는 원리

	// 1. template
	// 2. auto			// 1,2 는 동일 한 규칙
	// 3. decltype

}