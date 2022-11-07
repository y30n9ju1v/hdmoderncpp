// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <complex>
using namespace std::chrono; 

using namespace std::literals; // C++11 operator"" ���� ����
								// �پ��� ���ͷ� ���̻簡 �ֽ��ϴ�.

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello"); // const char*
	foo("hello"s); // string operator""s("hello") ȣ��
			
	std::chrono::seconds s = 1h + 20min + 20s;
					// hours ��ü + minutes ��ü + seconds ��ü

	std::cout << s.count() << std::endl; // 4820


	std::complex<double> c1(3);  // 3 + 0i
	std::complex<double> c2(3i); // 0 + 3i
								// c2(0, 3)
}

