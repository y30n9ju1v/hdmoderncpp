// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// STL �˰��� �Լ��� ���� �Ҷ� 

//	std::for_each(v.begin(), v.end(), "�Ϲݴ����Լ�");
//	std::for_each(v.begin(), v.end(), "�Ϲݴ����Լ���ü");


	// C++11 ���ʹ� �Լ��� �Լ���ü ��� ����ǥ���� ����
	std::for_each(v.begin(), v.end(), 
					[](int n) { std::cout << n << std::endl; });
}





