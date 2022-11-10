#include <iostream>
#include <string>
#include <vector>

// github �� �ִ� 
// "4_forwarding_reference2.cpp" "4_forwarding_reference3.cpp"
// ������ �ּ���.

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;
public:
	// move �� �����ϴ� setter ����� ��� 
	// => ���� �ڵ�� "���1" �� �����ϴ�.
	
	// ��� 1. 2���� setter �����
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }

	// ��� 2. forwarding reference ���
	template<typename T> void set_name(T&& n)
	{
		// ������ �´� ���� ?
//		name = n;					// �׻� ����
//		name = std::move(n);		// �׻� move
		name = std::forward<T>(n);	// <== ����
	}
};
int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;
	p.set_name(s1);				// copy �Ǿ�� �Ѵ�.
	p.set_name(std::move(s2));	// move �Ǿ�� �Ѵ�.

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; // ""

	//====================
	std::string s3 = "kim";
	const std::string s4 = "kim";

	// �Ʒ� �ڵ带 "���1" �� "���2" �� ������ ������ ������
	// ��� 1. const std::string& �Լ� �Ѱ��� ��� ó���˴ϴ�.
	// ��� 2. string&, const string& ������ ���� �����ϰ� �˴ϴ�.
	p.set_name(s3);
	p.set_name(s4);

	// ���� ��� 2. template �̶�� 
	//			  �Ʒ�ó�� string �� �ƴ� ��쵵 �Լ� �����˴ϴ�.
	//				�� "name = 3.4" ������ ������ �߻�
	p.set_name(3.4); 

}

