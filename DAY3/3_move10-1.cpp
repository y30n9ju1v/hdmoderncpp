#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Object
{
	int id;
	std::string name;
	T data;

public:
	Object() {}


	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}
	// move �����ڿ����� ��� ����� "std::move()" �� �Űܶ�!
	// �Ʒ� �ڵ忡�� "noexcept" �� ��� �ؾ� �ұ�� ?
	Object(Object&& other) noexcept 
		: id(other.id), 
		  name(std::move(other.name)),
		  data(std::move(other.data))
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; 
	Object o3 = std::move(o1); 
	Object o4 = std::move_if_noexcept(o2);

}

