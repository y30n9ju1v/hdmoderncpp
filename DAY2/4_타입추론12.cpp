template<typename T> void f1(T a, T b)
{
}
template<typename T> void f2(T& a, T& b)
{
}

int main()
{
	// "orange" 타입 : const char[7]
	// "apple"  타입 : const char[6]
	// 즉, "orange", "apple"은 다른 타입입니다

	f1("orange", "apple"); // ok
			// => 배열을 "값 타입(T a)로 받고 있으므로 포인터로 변경"
			//	  되어서 전달 됩니다.
			// "orange" 타입 : const char[7] => const char*
			// "apple"  타입 : const char[6] => const char*

	f2("orange", "apple"); // error. 왜 에러일까요 ?
			// => 배열을 그대로 전달
			// => 같은 타입을 요구하는데 다른 타입 입니다.
	f2("orange", "banana"); // ok
}

// decay 현상 : 배열을 보낼때 "포인터"로 변경되어 받게 되는현상