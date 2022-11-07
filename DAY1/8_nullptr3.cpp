//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0);		// int,		'0' �� int Ÿ�� ���ͷ�
	foo(0.0);	// double,	'0.0' �� double Ÿ�� ���ͷ�
	foo(false);	// bool		'false' �� bool Ÿ�� ���ͷ�
	foo(nullptr); // char*  'nullptr' �� ������ ���ͷ�

	// nullptr �� ��Ȯ�� Ÿ���� �����Ͱ� �ƴ� "std::nullptr_t"
	
	std::nullptr_t arg = nullptr;

	// std::nullptr_t Ÿ���� ��� ������ �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
	int*  p1 = arg;
	char* p2 = arg;

}



