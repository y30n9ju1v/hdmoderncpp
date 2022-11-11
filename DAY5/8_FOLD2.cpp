#include <iostream>
#include <vector>
template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// �ٽ� 1. �ʱⰪ�� "0" �� �ƴ϶� "std::cout" �� �ɼ��� �ֽ��ϴ�.
	// (std::cout << ... << args);
	// (((std::cout << 1 ) << 2 ) << 3)


	// �ٽ� 2. + �� �ƴ϶� ���� ���� ������ Ȱ���ϼ���!!
	//        "<<", "," ��
	// pack �̸� ��ġ���� �̸� �� �ƴ϶� pack �� ����ϴ� ���ϵ� ����
	(printv(args), ...);
	// ( printv(1), ( printv(2), ( printv(3), printv(4) )))
}

template<typename C, typename ... Types>
void insert_container(C& c, Types...args)
{
	(c.push_back(args), ...);
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	std::vector<int> v;
	insert_container(v, 1, 2, 3, 4, 5, 6);
}



