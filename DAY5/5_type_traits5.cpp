#include <iostream>
#include <type_traits>

int main()
{
	std::remove_pointer<int***>::type n1;
					// => n1 �� int** �Դϴ�.
					// => ��, ������ �Ѱ� �� ���� �˴ϴ�.

	remove_all_pointer<int***>::type n;	
					// => n�� int �ǰ� ������ ������
					//    ��ƽ��ϴ�.
}
