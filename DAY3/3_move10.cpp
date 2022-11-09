#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}


	Object(const Object&) 
	{	
		std::cout << "copy" << std::endl;	
	}
	// move �迭 �Լ� ���鶧 ���� ����!!!

	// 1. ���ܰ� �߻����� �ʵ��� ���弼��
	//    ��κ� ������ ���� �����̹Ƿ� ���ܰ� ���� �����ϴ�.
	// 2. ���ܰ� ������ �����Ϸ����� �˸��� ���ؼ� noexcept �� �� ���̼���
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // �׻� ���� ������ ȣ��
	Object o3 = std::move(o1); // �׻� move ������ ȣ��
	Object o4 = std::move_if_noexcept(o2);
					// => move �����ڿ� ���ܰ� ���ٸ� move ������
					//                      �ִٸ� ���� ������ ���

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10);	// �̼����� ������ �����غ��ô�.
					// ���� ������ ��Ҹ� ū ���۷� �ű涧
					// "std::move_if_noexcept" ����մϴ�.

	std::cout << "----------------" << std::endl;
}

