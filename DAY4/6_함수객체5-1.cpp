#include <iostream>
#include <vector>
#include <algorithm>



struct show_function_object
{
	inline void operator()(int n) const
	{
		std::cout << n << std::endl;
	}
};

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
	
	show_function_object  sfo;
	show_function_object2 sfo2;

	my_for_each(v.begin(), v.end(), sfo ); // for_each(show_function_object  );
	my_for_each(v.begin(), v.end(), sfo2); // for_each(show_function_object2  );

	// �Լ��� �ƴ� �Լ� ��ü�� ����ϸ�
	// ��ó�� �ٸ� Ÿ���� �Լ���ü�� ������

	// ���� : �������� for_each �Լ��� �����ȴ�. �ڵ� �޸� ����
	// ���� : operator() �� �ζ��� ġȯ �˴ϴ�. �ӵ��� ���� ���ϴ�.
	
}

