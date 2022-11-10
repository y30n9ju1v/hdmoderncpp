#include <iostream>
#include <vector>

int main()
{
	std::vector<int>  v1 = { 0,0,0,0,0 };
	std::vector<bool> v2 = { 0,0,0,0,0 };

	auto a1 = v1[0]; // int a1
	auto a2 = v2[0]; // bool �� �ƴ� bool ������ �䳻�� proxy ��ü

	// �ٽ� : �Ʒ� Ÿ�� ��� ��� ������ ������
	// => auto ������ ����� �ٸ� Ÿ���ϼ��� �ִ� �� �˾� �μ���
	//    vector<bool> �� operator [] ���� proxy ����� ����ϴ�
	//    ��찡 ���� �ֽ��ϴ�.
	std::cout << typeid(a1).name() << std::endl; // int
	std::cout << typeid(a2).name() << std::endl;


	for (auto& e : v1) // ok
	{	
	}

	for (auto& e : v2) // error.. �� ?? �����ϱ�� ?
	{	
		// �ᱹ "�ݺ���"�� �Ʒ� ó�� ������ �˴ϴ�.
		auto& e = *first; // �̶� "*first" �� ��ȯ���� bool& �̾ƴ�
						  // proxy �ӽð�ü(rvalue) �Դϴ�.
	}
}




