#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1,2,3 �ε�
	// args �� ��� ��ҿ����ؼ� printv �� ����ϰ� �ʹ�.

//	printv(args...); // printv(1,2,3) �̹Ƿ� ����!

//	printv(args)...; // �ǵ� : printv(1), printv(2), printv(3)
					 // error

	// �ٽ� : pack expansion �� ��� ��ġ���� ������ ���� �ƴմϴ�.
	// 1. �Լ� ȣ��� () ��
	// 2. {} �ʱ�ȭ ���� �ȿ����� ����

	int x[] = { (printv(args), 0)... }; 
		   // { (printv(1),0), (printv(2),0), (printv(3),0) };
}


int main()
{
	foo(1, 2, 3);
}

