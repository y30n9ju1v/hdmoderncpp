#include <iostream>
#include <vector>
#include <algorithm>

// �Լ���ü�� ���� 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// �־��� �������� "3�� ���"�� ã�� �ʹ�. 
	// => 3��° ���ڴ� �ݵ�� �����Լ�(���ڰ� �Ѱ�) �̾�� �մϴ�.
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// �־��� �������� 1��° ������ "k �� ���" �� ã�� �ʹ�.!

	auto p2 = std::find_if(v.begin(), v.end(), "�����Լ� + k��");

}

// �ϱ� ��ü(first class object)
// => �Լ� ���ڷ� ���� ������ ��ü
// => C/C++������ "�Լ�"�� �ϱ� ��ü�̴�.

// Closure(Ŭ����)
// => ���ƿ� ���� ���������� ĸ���Ҽ� �ִ� �ϱް�ü

// �Ϲ��Լ� : �ϱް�ü������ Ŭ������ �ƴմϴ�.
// �Լ���ü : Ŭ�����Դϴ�.!





