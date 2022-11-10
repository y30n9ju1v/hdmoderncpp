#include <iostream>
#include <vector>
#include <algorithm>


inline void show1(int n) { std::cout << n << std::endl;}
inline void show2(int n) { std::cout << n << std::endl; }

// STL �� for_each �� ���� ����� ���ô�.
template<typename T, typename F>
void my_for_each(T first, T last, F f)
{
	while (first != last)
	{
		f(*first);
		++first;
	}
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	my_for_each(v.begin(), v.end(), show1);
				// => �� �ڵ�� show1 �Լ��� 10�� ȣ��˴ϴ�.
				// => show1 �� �ζ��� �Լ��� �ζ��� ġȯ�ɼ� �����ϴ�.
				// => ������ �Լ��� �Ʒ� ����ε� ������ ���ڰ� �Լ� ������ �Դϴ�.
//  my_for_each( iterator, iterator, void(*)(int))

	my_for_each(v.begin(), v.end(), show2);
//	my_for_each(iterator, iterator, void(*)(int))


	// for_each �� "�Ϲ� �Լ�" ����
	// ���� : ��ó�� "show1" "show2" �� ������ ������
	//	     for_each �� �Ѱ� �Դϴ�.
	//		 �ڵ� �޸� ����

	// ���� : �Ѱ��� for_each �� 2���� �Լ� ������ ġȯ�Ҽ��� �����ϴ�.
	//       �ζ���ġȯ�� �ȵǰ�, ȣ�� �Դϴ�.
	//	     �����ϴ�.

	my_for_each(v.begin(), v.end(), show1); // for_each(void(*)(int)) ����
	my_for_each(v.begin(), v.end(), show2); // for_each(void(*)(int)) ����
}


