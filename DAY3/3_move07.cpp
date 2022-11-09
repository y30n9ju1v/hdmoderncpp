// move �迭�Լ� ������ ��� ����� move�� �Űܶ�!
#include <iostream>
#include <string>

class Cat
{
	char* name;
	int   age;
	std::string addr;
public:
	Cat(const char* n, int a, const std::string& add) 
		: age(a), addr(add)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// ���� ������
	Cat(const Cat& c) : age(c.age), addr(c.addr)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}

	// �ٽ� : move �����ڿ����� ��� ����� move�� �ű⼼��!
	// addr(c.addr) : string �� ���� ������ ȣ�� - ���ڿ��� ���� �Դϴ�
	// addr(std::move(c.addr)) : string �� move ������ ȣ��

	// ��, primitive Ÿ���� ��� "std::move" �� �־ �ǰ� ��� �˴ϴ�.
	Cat(Cat&& c) : age(c.age), name(c.name), addr(std::move(c.addr))
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}




	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name; 
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;
		name = c.name;	
		c.name = nullptr;

		return *this;
	}


};
int main()
{

}





