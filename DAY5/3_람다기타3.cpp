// "3_람다기타3" => 3-1 로 변경하고
// "3_람다기타3" 다시 만드세요

int main()
{
	auto f1 = [](int a, int b) { return a + b; };


	decltype(f1) f2;
	decltype(f1) f3 = f1;
}