// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// �ݺ��ڸ� ��� ���
	// 1. C++98 ��Ÿ��
	// ���� : �����̳� ��ü��, �ݺ��� Ÿ�Ե� ����Ǿ�� �մϴ�.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();


	// 2. C++11 ��Ÿ��. auto ���
	// => �����̳� ����� �ݺ��� Ÿ���� �ڵ����� �����
//	auto p1 = v.begin(); // �� �ڵ��
//	auto p2 = v.end();   // v �� raw array ��� error

	// ��� �Լ� begin ���� �Ϲ� �Լ� begin �� �������� �����ϴ�.
	// => v�� raw array �� ��쿡�� �� ���� �մϴ�.
	auto p1 = std::begin(v); 
	auto p2 = std::end(v);   

//	auto sz1 = v.size();	 // �迭�� ����
	auto sz2 = std::size(v); // �迭�� ����


	// C++20 ���� ���ο� begin �� ���� �մϴ�.
	auto p3 = std::ranges::begin(v); // C++20

	// ���ο� begin �� ���� ����..
	// => �Ʒ� �ڵ带 �߻����� ������
	auto p4 = std::begin( std::vector<int>{1, 2, 3} );

	int n1 = *p4; // ??
}