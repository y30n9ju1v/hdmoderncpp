#include <iostream>
#include <vector>
#include <algorithm>


bool foo(int n) { return n % 3 == 0; }

struct IsDivide
{
	int value;	// �Լ� ��ü�� ��� ����Ÿ�� �ְ�

	IsDivide(int n) : value(n) {} // �����ڵ� �ֽ��ϴ�.

	bool operator()(int n) const {	return n % value == 0;}
};
int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);
	bool b = f(10); // �ᱹ "10 % k == 0" �� �����ϴ� ���� �Լ�
					// ��, f�� k�� ���� ĸ���� �����Լ� �Դϴ�.

	// �־��� �������� 1��° ������ "k �� ���" �� ã�� �ʹ�.!
	auto p2 = std::find_if(v.begin(), v.end(), f);

	std::cout << *p2 << std::endl; // 6

	// �ӽð�ü���·� ����
	auto p3 = std::find_if(v.begin(), v.end(), foo);	
								// => ���� �Լ��� ����

	auto p4 = std::find_if(v.begin(), v.end(), IsDivide(k));
								// => ���� �Լ� + ��������k ����
}





