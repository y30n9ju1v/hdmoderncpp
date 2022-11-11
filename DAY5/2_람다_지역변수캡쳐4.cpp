// 149
int main()
{
	int v1 = 0, v2 = 0;

	// 
	auto f1 = [v1, &v2](int a) { ... }; // v1은 값, v2는 참조
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... }; // 모든 지역변수를 "값 캡쳐"
	auto f4 = [&](int a) { ... }; // 모든 지역변수를 "참조 캡쳐"

	auto f5 = [=, &v2](int a) { ... }; // v2는 참조, 나머지는 "값"
	auto f6 = [&,  v2](int a) { ... }; // v2는 값,   나머지는 "참조"
	auto f7 = [&, &v2](int a) { ... }; // error. 
										// 디폴트값과 다른 경우만 표기

	// 변수 이름 변경
	// int  x = v1;
	// int& y = v2;
	auto f8 = [x = v1, &y = v2](int a) { x, y };

	// int x = std::move(v1)
	auto f9 = [x = std::move(v1)](int a) { x };
}




