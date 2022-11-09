#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	//------------------

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy" << std::endl;
	}
	// �ӽð�ü�϶��� ���� 
	// ��������ڸ� ������ �����մϴ�.
	Cat(Cat&& c) : name(c.name), age(c.age) // ��� ����� ��������
	{
		// �ӽð�ü�� �ı��ɶ� �ڿ��� ������ ���ϰ� �ϱ�����
		// �ڿ� �����͸� 0 ����
		// => �� �ڵ带 �Ϸ��� �ӽð�ü(rvalue) �� ���� ������ ����
		//    �ؾ� �մϴ�.
		//    "�����(const)���� �ӽð�ü�� ����ų�� �־�� �մϴ�.
		c.name = nullptr;

		std::cout << "move" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1; // copy

	Cat c3 = foo(); // move �̼����� �޸� �׸��� ������ ���ô�.
}