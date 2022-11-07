//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0);		// int,		'0' 은 int 타입 리터럴
	foo(0.0);	// double,	'0.0' 은 double 타입 리터럴
	foo(false);	// bool		'false' 는 bool 타입 리터럴
	foo(nullptr); // char*  'nullptr' 은 포인터 리터럴

	// nullptr 의 정확한 타입은 포인터가 아닌 "std::nullptr_t"
	
	std::nullptr_t arg = nullptr;

	// std::nullptr_t 타입은 모든 종류의 포인터로 암시적 형변환 됩니다.
	int*  p1 = arg;
	char* p2 = arg;

}



